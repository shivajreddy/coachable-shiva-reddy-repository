// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    // edge case: single element of 1st element is peek
    if (n == 1 || nums[0] > nums[1])
      return 0;
    // edge case: last element is peek
    if (nums[n - 1] > nums[n - 2])
      return n - 1;

    // binary search
    int left = 1, right = n - 2;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
        return mid;
      }
      if (nums[mid - 1] < nums[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;  // or right
  }
};

int main() {
  auto test = [](Solution sol, vector<int>& nums, int expected) {
    int result = sol.findPeakElement(nums);
    printf("EXPECTED: %d\n", expected);
    printf("RESULT : %d\n\n", result);
  };

  Solution sol;
  vector<int> nums;
  int expected;

  // Test 1
  nums = {1, 2, 3, 1};
  expected = 2;
  test(sol, nums, expected);

  // Test 2
  nums = {1, 2, 1, 3, 5, 6, 4};
  expected = 5;
  test(sol, nums, expected);
}

// 27. Remove Element
// https://leetcode.com/problems/remove-element

#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int p = 0;  // Position for non target number to be placed
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[p] = nums[i];
        p++;
      }
    }
    return p;
  }
};

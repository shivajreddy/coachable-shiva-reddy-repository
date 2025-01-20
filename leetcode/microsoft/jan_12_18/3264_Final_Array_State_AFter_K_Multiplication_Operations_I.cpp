// 3264. Final Array State AFter K Multiplication Operations I
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <utility>

using std::vector;

class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

    typedef std::pair<int, int> Pair;

    // Create a Min-Heap of nums along with their input
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> mh;

    // Add nums to min-heap with their indexes. Time: Log(n)
    for (int i = 0; i < nums.size(); i++)
      mh.push({nums[i], i});

    // for (int i = 0; i < k; i++) {
    for (int i = 0; i < k && !mh.empty(); i++) {
      Pair smallest = mh.top();
      mh.pop();
      nums[smallest.second] = smallest.first * multiplier;
      Pair new_entry = Pair(smallest.first * multiplier, smallest.second);
      mh.push(new_entry);
    }

    return nums;
  }
};

/**
 * Helper function to print a vector in the format [x,y,z,...].
 */
void printVector(const std::vector<int>& arr) {
  std::cout << "[";
  for (size_t i = 0; i < arr.size(); i++) {
    std::cout << arr[i];
    if (i + 1 < arr.size()) {
      std::cout << ",";
    }
  }
  std::cout << "]";
}

/**
 * Test runner that takes a vector of `nums`, calls the Solution,
 * and compares the result with `expected`.
 */
void runTest(const std::vector<int>& nums, int k, int multiplier,
             const std::vector<int>& expected) {
  // Create a copy of nums because getFinalState modifies its argument
  std::vector<int> inputCopy = nums;

  // Run the solution
  Solution sol;
  std::vector<int> result = sol.getFinalState(inputCopy, k, multiplier);

  // Print Input
  std::cout << "Input: nums = ";
  printVector(nums);
  std::cout << ", k = " << k << ", multiplier = " << multiplier << "\n";

  // Print Expected
  std::cout << "Expected: ";
  printVector(expected);
  std::cout << "\n";

  // Print Received
  std::cout << "Received: ";
  printVector(result);
  std::cout << "\n\n";
}

int main() {
  {  // Test case 1
    std::cout << "TEST CASE 1\n";
    std::vector<int> nums = {2, 1, 3, 5, 6};
    std::vector<int> expect = {8, 4, 6, 5, 6};
    runTest(nums, 5, 2, expect);
  }

  {  // Test case 2
    std::cout << "TEST CASE 2\n";
    std::vector<int> nums = {1, 2};
    std::vector<int> expect = {16, 8};
    runTest(nums, 3, 4, expect);
  }

  {  // Test case 3
    std::cout << "TEST CASE 3\n";
    std::vector<int> nums;
    std::vector<int> expect;
    runTest(nums, 5, 2, expect);
  }

  {  // Test case 4
    std::cout << "TEST CASE 4\n";
    std::vector<int> nums = {3};
    std::vector<int> expect = {12};
    runTest(nums, 2, 2, expect);
  }

  {  // Test case 5: k = 0
    std::cout << "TEST CASE 5\n";
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expect = {1, 2, 3};
    runTest(nums, 0, 2, expect);
  }
  {  // Test case 6: k = 0
    std::cout << "TEST CASE 5\n";
    std::vector<int> nums = {1, 3, 5};
    std::vector<int> expect = {27, 9, 15};
    runTest(nums, 5, 3, expect);
  }

  return 0;
}

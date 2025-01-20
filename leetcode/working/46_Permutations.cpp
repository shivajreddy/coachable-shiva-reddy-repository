// 46. Permutations
// https://leetcode.com/problems/permutations

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
Observations:

  example: 1, 2, 3

                ___
      1__       2__         3__
  12_  13_    21_  23_    31_  32_
  123  132    213  231    312  321

*/

class Solution {
 private:
  void backtrack(vector<int>& nums, vector<bool>& used,
                 vector<int>& current_path, vector<vector<int>>& result) {
    // Base Condition
    if (current_path.size() == nums.size()) {
      result.push_back(current_path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {

      // skip already used number
      if (used[i])
        continue;

      used[i] = true;  // mark as read
      current_path.push_back(nums[i]);
      backtrack(nums, used, current_path, result);

      current_path.pop_back();
      used[i] = false;
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    vector<int> current_path;

    backtrack(nums, used, current_path, result);

    return result;
  }
};

int main() {
  Solution sol;

  auto run_test = [](Solution sol, vector<int>& nums,
                     vector<vector<int>>& expected) {
    auto result = sol.permute(nums);
    cout << "RESULT  : [";
    for (int i = 0; i < result.size(); i++) {
      cout << "[";
      auto v = result[i];
      for (int j = 0; j < v.size(); j++) {
        cout << v[j];
        if (j != v.size() - 1)
          cout << ",";
      }
      cout << "]";
      if (i != expected.size() - 1)
        cout << ",";
    }
    cout << "]" << endl;

    cout << "EXPECTED: [";
    for (int i = 0; i < expected.size(); i++) {
      cout << "[";
      auto v = expected[i];
      for (int j = 0; j < v.size(); j++) {
        cout << v[j];
        if (j != v.size() - 1)
          cout << ",";
      }
      cout << "]";
      if (i != expected.size() - 1)
        cout << ",";
    }
    cout << "]\n" << endl;
  };

  // Test Case 1
  {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> expected = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    run_test(sol, nums, expected);
  }
  // Test Case 2
  {
    vector<int> nums = {0, 1};
    vector<vector<int>> expected = {{0, 1}, {1, 0}};
    run_test(sol, nums, expected);
  }
  // Test Case 3
  {
    vector<int> nums = {1};
    vector<vector<int>> expected = {{1}};
    run_test(sol, nums, expected);
  }

  return 0;
}

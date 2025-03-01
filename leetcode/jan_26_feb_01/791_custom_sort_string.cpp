// 791. Custom Sort String
// https://leetcode.com/problems/custom-sort-string

#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  string customSortString(string order, string s) {
    string result;

    return result;
  }
};

int main() {

  auto run_test = [](Solution sol, string order, string s, string expected) {
    std::cout << "EXPECTED: " << expected << "\n";
    std::cout << "RECEIVED: " << sol.customSortString(order, s);
    std::cout << "\n" << std::endl;
  };

  Solution sol;

  run_test(sol, "cba", "abcd", "cbad");
  run_test(sol, "bcafg", "abcd", "bcad");

  return 0;
}

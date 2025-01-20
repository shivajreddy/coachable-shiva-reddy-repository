// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
 public:
  string convert(string s, int numRows) {
    // Edge Case
    if (numRows == 1 || numRows >= s.length())
      return s;

    // Vector of strings that will represent each row
    vector<string> rows(min(numRows, (int)s.size()));

    // track the current position
    int current_row = 0;
    bool going_down = true;

    // iterate over the string
    for (char c : s) {
      rows[current_row] += c;

      // hit bottom row or top row, change direciton
      if (current_row == 0)
        going_down = true;
      else if (current_row == numRows - 1)
        going_down = false;

      // Move to next row
      current_row += going_down ? 1 : -1;
      ;
    }

    // cocatenate all rows to final string
    string result;
    for (const string& row : rows)
      result += row;

    return result;
  }
};

int main() {
  Solution sol;
  auto run_test = [](Solution sol, string s, int numRows, string expected) {
    std::cout << s << " " << numRows << std::endl;
    std::cout << sol.convert(s, numRows) << std::endl;
    std::cout << expected << "\n" << std::endl;
  };

  run_test(sol, "PAYPALISHIRING", 3, "PINALSIGYAHRPI");
  run_test(sol, "PAYPALISHIRING", 4, "PINALSIGYAHRPI");
  run_test(sol, "A", 1, "A");

  return 0;
}

// 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii

#include <string>

using std::string;

/*
Observations: 
- skip spaces

Initial Thoughts:
- stack to track of number(could be multiple digits), so keep storing in string,
  and convert to int only when we hit a symbol

- BODMAS: Bracket, Order of powers, Division, Multiplication, Addition, Subtraction

*/

class Solution {
 public:
  int calculate(string s) {

    int prev_num = 0, curr_num = 0;

    char curr_operation = '+';

    int result = 0;

    int idx = 0;

    while (idx < s.length()) {
      char current_char = s[idx];
      if (current_char == ' ') {
        idx++;
        continue;
      }
    }

    return result;
  }
};

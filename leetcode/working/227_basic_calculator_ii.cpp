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
#include <cctype>
class Solution {
 public:
  int calculate(string s) {
    int curr_num = 0, prev_num = 0, result = 0;
    char curr_operation = '+';  // Initially assume '+' as the operation

    for (int idx = 0; idx < s.length(); ++idx) {
      char ch = s[idx];

      // If the character is a digit, parse the number
      if (isdigit(ch)) {
        curr_num = 0;  // Reset current number
        while (idx < s.length() && isdigit(s[idx])) {
          curr_num = curr_num * 10 + (s[idx] - '0');
          ++idx;
        }
        --idx;  // Adjust for the loop increment
      }

      // If the character is an operator or it's the last character
      if (!isdigit(ch) && ch != ' ' || idx == s.length() - 1) {
        switch (curr_operation) {
          case '+':
            result += prev_num;   // Add the previous number to the result
            prev_num = curr_num;  // Update previous number
            break;
          case '-':  // if -ve treat as +ve
            result += prev_num;
            prev_num = -curr_num;
            break;
          case '*':
            prev_num *= curr_num;  // Update previous number directly
            break;
          case '/':
            prev_num /= curr_num;  // Update previous number directly
            break;
        }
        curr_operation = ch;  // Update current operation
        curr_num = 0;         // Reset current number
      }
    }

    // Add the last number to the result
    result += prev_num;
    return result;
  }
};

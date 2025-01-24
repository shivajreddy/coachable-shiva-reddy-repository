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
- Main idea of the problem : how to undo  (+ or -) when we encounter (* or /)
- we should treat + and - as same operation, similary * and /
  because these operations are inverse of each other

Approach:
- Instead of using a stack to manage numberes nad operations, we can use variables
  prev_num : track the last computed value for higher-precedence operations
- Addition & Subtraction directly update the result.
- Multiplication & Division modify the 'prev_num' to "undo" their effect
  when a lower-precedence operation is encountered.

Core Idea:
   - The main challenge is handling the precedence of * and / over + and -
   - To achieve this:
     - Treat + and - as a single operation (low precedence).
     - Treat * and / as a single operation (high precedence).
   - When encountering * or /, adjust 'prev_num' without immediately updating the 'result'.
   - For + and -, finalize the previous operation by adding 'prev_num' to 'result' and resetting 'prev_num'.


Processing the String:
   - Iterate through the string, handling characters based on their type:
     - Digit: Parse and accumulate the current number.
     - Operator: Perform the appropriate calculation based on the current operation.
     - End of String: Add the last number (`prev_num`) to the result.
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
          idx++;
        }
        idx--;  // Adjust for the loop increment
      }

      // If the character is an operator or it's the last character
      if (!isdigit(ch) && ch != ' ' || idx == s.length() - 1) {
        switch (curr_operation) {
          case '+':
            result += prev_num;   // Add the previous number to the result
            prev_num = curr_num;  // Update previous number
            break;
          case '-':  // -ve treat as +ve
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

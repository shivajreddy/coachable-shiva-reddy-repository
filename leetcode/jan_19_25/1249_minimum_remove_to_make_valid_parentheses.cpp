// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

#include <string>

using std::string;

/*
Input: s = lee(t(c)o)de)
              | | | |  |
Output:
lee(t(c)o)de    lee(t(c)ode)      lee(t(co)de)
   | | | |         | | |   |         | |  |  |

Input: s = "a)b(c)d"
Output: "ab(c)d"

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

/*
Observations & Approach:

- Use a stack. (Because we have to deal with matching the parentheses in the most recent item pattern, i.e, LIFO)
- we will use the stack in such a way that it helps us validate a matching pair
- we will only hold the indexes of the open parentheses in the stack.
- when ever we encounter a closing parentheses, we pop the top item on stack,
  which implies that this was the most recent opening parentheses that the current
  closing parentheses will get paired with
  - but if the stack was empty, then the current closing parentheses doesnt have a pair,
    so we mark this index as 

  Space: O(n) , since we have a boolean array of same size as input
  Time: O(n), line time complexity sice we treverse a total of 2n in worst case


  - First pass
 - Iterate over the input string, for finding and marking all the invalid closing parentheses:
  - if it is open, collect its index in a stack
  - if it closed:
    - check if there are enough openings on the stack

  - Second pass
  - Iterate over the indexes in the stack
   - since these are the opening parentheses that haven't been paired to a closing parentheses
     yet, and they couldnt be. so we mark them as to be removed.

*/

class Solution {
 public:
  string minRemoveToMakeValid(string s) {

    // stack to trace the open indices
    stack<int> open_indices;

    // mark indices to remove
    vector<bool> to_remove(s.length(), false);

    // First pass: mark invalid Parentheses
    for (int i = 0; i < s.length(); i++) {
      char current_char = s[i];
      if (current_char == '(') {
        open_indices.push(i);
      } else if (current_char == ')') {
        if (open_indices.empty())
          to_remove[i] = true;
        else
          open_indices.pop();
      }
    }

    // Mark unmatched open parentheses
    while (!open_indices.empty()) {
      to_remove[open_indices.top()] = true;
      open_indices.pop();
    }

    // construct result string without marked indices
    string result;
    for (int i = 0; i < s.length(); i++) {
      if (!to_remove[i])
        result += s[i];
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto run_test = [](Solution sol, string s) {
    std::cout << "INPUT : " << s << std::endl;
    std::cout << "OUTPUT: " << sol.minRemoveToMakeValid(s) << "\n" << std::endl;
  };

  run_test(sol, "lee(t(c)o)de)");
  run_test(sol, "a)b(c)d");
  run_test(sol, "))((");
}

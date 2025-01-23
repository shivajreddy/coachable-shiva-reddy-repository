// 339. Nested List Weight Sum
// https://leetcode.com/problems/nested-list-weight-sum

#include <vector>

using std::vector;

class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.

  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger& ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger>& getList() const;
};

/*

Approach:
using recursion to go item by item, if its a list call the recursive function with depth+1

Time:  O(n) for n indiviusal integers in the given input
Space: O(n) if considering the recursive call stack, else O(1)
*/

class Solution {

 private:
  int get_total(const vector<NestedInteger>& list, int depth) {
    int result = 0;
    for (auto item : list) {
      if (item.isInteger()) {
        result += (item.getInteger() * depth);
      } else {
        result += (get_total(item.getList(), depth + 1));
      }
    }
    return result;
  }

 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    return get_total(nestedList, 1);
  }
};

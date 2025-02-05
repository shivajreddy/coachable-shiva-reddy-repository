// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator

#include <stack>
#include <vector>

using std::stack;
using std::vector;

/*
Design Strategy:
- Lazily evaluate nested lists
- Use a stack for efficient traversal
- Maintain O(1) space complexity for next()
- O(n) space for pre-processing the nested list

Key Implementation Details:
- Stack stores NestedInteger elements
- Reverse order insertion to preserve original traversal sequence
- hasNext() dynamically flattens nested lists
- Ensures top of stack is always an integer when hasNext() is called

Time Complexity:
- next(): O(1)
- hasNext(): Amortized O(1), worst case O(n)

Space Complexity: 
- O(n), where n is total number of nested elements

Core Invariants:
- Only flatten elements when necessary
- Guarantee top of stack is an integer before returning from hasNext()
- Stop iteration when stack becomes empty

Optimization Considerations:
- Avoid full list flattening during initialization
- Defer nested list expansion until required
- Minimize unnecessary stack manipulations
*/

class NestedIterator {
 private:
  stack<NestedInteger> st;

  /* 
  // This will flatten the given NestedInteger, but we can avoid this 
  // for Optimization during initialization
  void flatten_stack(NestedInteger& ni) {
    if (ni.isInteger()) {
      st.push(ni);
      return;
    }
    const vector<NestedInteger>& list = ni.getList();
    for (int i = list.size() - 1; i >= 0; i--) {
      st.push(list[i]);
    }
  }
  */

 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; i--) {
      st.push(nestedList[i]);
    }
  }

  int next() {
    int result = st.top().getInteger();
    st.pop();
    return result;
  }

  bool hasNext() {
    while (!st.empty()) {
      NestedInteger top = st.top();
      if (top.isInteger())
        return true;

      st.pop();
      const vector<NestedInteger>& list = top.getList();
      for (int i = list.size() - 1; i >= 0; i--) {
        st.push(list[i]);
      }
    }
    return false;
  }
};

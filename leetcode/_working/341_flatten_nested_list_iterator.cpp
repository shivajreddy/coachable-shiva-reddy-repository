// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator

#include <vector>
using std::vector;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger>& getList() const;
};

void reverse_vector(vector<NestedInteger>& v) {
  int l = 0, r = v.size() - 1;
  while (l < r) {
    NestedInteger temp = v[l];
    v[l] = v[r];
    v[r] = temp;
    l++;
    r--;
  }
}

class NestedIterator {
 private:
  vector<NestedInteger> stack;

 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    reverse_vector(nestedList);
    this->stack = nestedList;
  }

  int next() {
    int result = this->stack.back().getInteger();
    this->stack.pop_back();
    return result;
  }

  bool hasNext() {
    while (this->stack.size() > 0) {
      NestedInteger top = this->stack.back();
      if (top.isInteger()) {
        return true;
      }
      this->stack.pop_back();
      vector<NestedInteger> nested_list = top.getList();
      reverse_vector(nested_list);
      for (auto item : nested_list) {
        this->stack.push_back(item);
      }
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

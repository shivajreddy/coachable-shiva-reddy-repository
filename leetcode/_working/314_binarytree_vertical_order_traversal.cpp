// 314. Binary Tree Vertical Oder Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {}
};

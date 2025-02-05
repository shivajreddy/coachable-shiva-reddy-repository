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

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using std::max;
using std::min;
using std::pair;
using std::queue;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    // Base Case
    if (!root)
      return {};

    // Hashmap: <col id of key>: <list of all node-values>
    unordered_map<int, vector<int>> map;

    // double ended que for BFS
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    int min_col = 0, max_col = 0;

    while (!q.empty()) {

      auto [node, col] = q.front();
      q.pop();

      if (!node)
        continue;

      // Process Current Node
      map[col].push_back(node->val);

      min_col = min(col, min_col);
      max_col = max(col, max_col);

      // Process Left Node
      if (node->left)
        q.push({node->left, col - 1});

      // Process Right Node
      if (node->right)
        q.push({node->right, col + 1});
    }
    vector<vector<int>> result;
    for (int col = min_col; col <= max_col; col++) {
      result.push_back(map[col]);
    }

    return result;
  }
};

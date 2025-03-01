// 199. Binary Tree Rigth Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root)
      return {};

    vector<int> result;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    // BFS
    while (!q.empty()) {
      auto [node, lvl] = q.front();
      q.pop();

      if (!node)
        continue;

      // add last value in the level to result
      if (result.size() == lvl) {  // found a new level
        result.push_back(node->val);
      } else {  // update value of existing level
        result[lvl] = node->val;
      }

      // add child nodes to queue
      q.push({node->left, lvl + 1});
      q.push({node->right, lvl + 1});
    }

    return result;
  }
};

// HELPERS
void print_vec(vector<int> nums) {
  for (int num : nums) {
    printf("%d ", num);
  }
  printf("\n");
}

int main() {

  auto test = [](Solution sol, TreeNode* root, vector<int> expected) {
    auto result = sol.rightSideView(root);

    printf("EXPECTED: ");
    print_vec(expected);

    printf("RESULT: ");
    print_vec(result);
    printf("\n");
  };

  Solution sol;
  vector<int> expected;
  TreeNode* root;

  // Test  1
  expected = {1, 3, 4};
  test(sol, root, expected);

  return 0;
}

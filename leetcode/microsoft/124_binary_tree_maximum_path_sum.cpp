#include <limits.h>
#include <algorithm>
#include <limits>

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
 private:
  // global result: maximum path sum encountered
  int _result = std::numeric_limits<int>::min();  // -inf

  int post_dfs(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    // Explore Left & Right sub trees
    int L = post_dfs(node->left);
    int R = post_dfs(node->right);

    int left_path_sum = L < 0 ? 0 : L;
    int right_path_sum = R < 0 ? 0 : R;

    // Process current node
    int curr_max_path_sum = left_path_sum + right_path_sum + node->val;

    // update global result
    if (_result < curr_max_path_sum)
      _result = curr_max_path_sum;

    return std::max(left_path_sum, right_path_sum) + node->val;
  }

 public:
  int maxPathSum(TreeNode* root) {
    post_dfs(root);
    return _result;
  }
};

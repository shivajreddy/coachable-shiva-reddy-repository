#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {}
};

class Solution
{
private:
    vector<int> result = {};

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr) {
            return result;
        }

        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);

        return result;
    }
};

int main()
{
    // Helper Function
    auto printVector = [&](vector<int> v) {
        for (const int &num : v) {
            cout << num << " ";
        }
        cout << endl;
    };

    Solution s;
    // Test 1
    {
        TreeNode *one = new TreeNode(1);
        TreeNode *two = new TreeNode(2);
        TreeNode *three = new TreeNode(3);
        one->right = two;
        two->left = three;

        auto result = s.inorderTraversal(one);
        printVector(result);
        printVector({ 1, 3, 2 });

        delete one;
        one = nullptr;
        delete two;
        two = nullptr;

        delete three;
        three = nullptr;
    }
};

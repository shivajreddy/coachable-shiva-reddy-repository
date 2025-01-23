// 1650. Lowest Common Ancestor of a Binary Tree III
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii

#include <iostream>
using namespace std;

// Definition for a node
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
  Node(int val) : val(val) {}
};

/*
  - Given that there is defincetely an LCA
  - This problem is like the linked problem to find the fist meeting point, where we traverse the two lists 
    twice because x + y is equal to y + x

  - start with two poitners each pointing to the two given nodes
  - check if both pointers are pointing to the same node. if yes return either of the nodes,
    since both point to same node
  - if not, we traverse upward for each node pointer
    - if we reached the root of the tree for one of the path, where its parent will be NULL, we move 
    it to point to the start node of the other path

  Time: log(n), worst case we travel 2 times the height of the tree i.e., 2.log(n) for n nodes in tree
  Space: O(1)
*/

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {

    Node* a = p;
    Node* b = q;

    while (a != b) {
      a = (a == nullptr) ? q : a->parent;
      b = (b == nullptr) ? p : b->parent;
    }

    return a;
  }
};

int main() {
  /*
         3
        / \
       5   1
      / \ / \
     6  2 0  8
       / \
      7   4
  */

  // Create the tree nodes
  Node* root = new Node(3);
  Node* node5 = new Node(5);
  Node* node1 = new Node(1);
  Node* node6 = new Node(6);
  Node* node2 = new Node(2);
  Node* node0 = new Node(0);
  Node* node8 = new Node(8);
  Node* node7 = new Node(7);
  Node* node4 = new Node(4);

  // Connect the tree
  root->left = node5;
  root->right = node1;
  node5->parent = root;
  node1->parent = root;
  node5->left = node6;
  node5->right = node2;
  node6->parent = node5;
  node2->parent = node5;
  node1->left = node0;
  node1->right = node8;
  node0->parent = node1;
  node8->parent = node1;
  node2->left = node7;
  node2->right = node4;
  node7->parent = node2;
  node4->parent = node2;

  // Solve the problem
  Solution solution;
  Node* lca = solution.lowestCommonAncestor(node7, node4);
  cout << "LCA of node 7 and node 4 is: " << lca->val << endl;  // Output: 2

  return 0;
}

// 1650. Lowest Common Ancestor of a Binary Tree III
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii

// Definition for a node
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
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

  return 0;
}

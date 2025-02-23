// 708. Insert into a Sorted Circular Linked List
// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

/*
struct Node {
  int val;
  struct TreeNode* next;
};

struct Node* insert(struct Node* head, int insertVal) {}
*/

#include <stdio.h>
#include <initializer_list>

class Node {
 public:
  int val;
  Node* next;
  Node() {}
  Node(int _val) : val(_val), next(NULL) {}
  Node(int _val, Node* _next) : val(_val), next(_next) {}
};

class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    // write solution here
    return NULL;
  }
};

// HELPER FUNCIONS
void print_ll(Node* head) {
  Node* curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("NULL\n");
}
void print_list(std::initializer_list<int> nums) {
  for (int num : nums) {
    printf("%d -> ", num);
  }
  printf("NULL\n");
}

int main() {
  Solution sol;
  Node* head;
  int insertVal;

  auto test = [](int test_no, Solution sol, Node* head, int insertVal,
                 std::initializer_list<int> expected) {
    printf("TEST: %d\n", test_no);
    sol.insert(head, insertVal);
    print_ll(head);
    print_list(expected);
    printf("\n");
  };

  // TEST 1
  head = new Node(3, new Node(4, new Node(1)));
  insertVal = 2;
  test(1, sol, head, insertVal, {3, 4, 1, 2});

  // TEST 2
  head = NULL;
  insertVal = 1;
  test(2, sol, head, insertVal, {1});

  // TEST 3
  head = new Node(1);
  insertVal = 0;
  test(3, sol, head, insertVal, {1, 0});

  return 0;
}

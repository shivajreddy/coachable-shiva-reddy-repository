// 708. Insert into a Sorted Circular Linked List
// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

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
    // Edge case : null check
    if (head == nullptr) {
      Node* new_node = new Node(insertVal);
      new_node->next = new_node;
      return new_node;
    }

    // Edge case: single node (head->new same as new->head)
    if (head->next == head) {
      Node* new_node = new Node(insertVal);
      head->next = new_node;
      new_node->next = head;
      return head;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != head) {
      // insert new node b/w prev and curr
      if (prev->val <= insertVal && insertVal <= curr->val) {
        break;
      }
      // insert at tail
      if (prev->val > curr->val) {
        if (insertVal >= prev->val || insertVal <= curr->val) {
          break;
        }
      }
      prev = curr;
      curr = curr->next;
    }

    // insert the new node
    Node* new_node = new Node(insertVal);
    prev->next = new_node;
    new_node->next = curr;

    return head;
  }
};

// HELPER FUNCIONS
void print_ll(Node* head) {
  Node* curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("NULL");
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
    printf("TEST::%d   ", test_no);
    print_ll(head);
    printf(" | %d\n", insertVal);
    head = sol.insert(head, insertVal);
    printf("RECEIVED: ");
    print_ll(head);
    printf("\nEXPECTED: ");
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

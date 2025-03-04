/*
- Implement a Stack class with push, pop, peek operations. Everything should be
implemented in O(1) worst-case runtime using a singly linked list to implement
it. If you have questions about the requirements you can ask me.
- Implement a Queue class with enqueue, dequeue, peek operations all in O(1). It
should use a singly linked list as well.
- Explain how a singly linked list differs from a doubly linked list. Then,
implement both. Write a method for removing the last element in both
implementations.
- You are given a pointer/reference to a node (not necessarily the head) in a
singly linked list. Implement a function to delete that node.
- Implement a function to reverse a singly linked list iteratively. What is the
time and space complexity?
- Write a function that returns the middle node of a linked list in O(n) time
and O(1) space without counting the length first.
- Write a function that determines whether a singly linked list represents a
palindrome. Optimize for O(n) time and O(1) space.
- What is a circular linked list? Implement a method to detect if a given linked
list is circular.
- Write a function that removes duplicates from an unsorted singly linked list.
What are the time and space tradeoffs?
- Given a linked list and a value X, modify the list so that all notes less than
X come before nodes greater than or equal to X. Maintain the relative order of
nodes.
- How do insertion and deletion differ in a doubly linked list compared to a
singly linked list? Implement a class for a DoublyLinkedList with insert and
delete methods.
*/

// Implement a Stack class with push, pop, peek operations.
// Everything should be implemented in O(1) worst-case runtime using a singly
// linked list to implement it.
#include <stdio.h>
#include <stdlib.h>

// LINKED LIST NODE
//------------------------------------------
struct ListNode {
  int val;
  ListNode* next;

  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}
};

// STACK
//------------------------------------------
/*
Implementation Details
 - Last In First Out
 - Underlying DataStructure: uses a singly linked list
 - Top item is the head of the linked list
 - New item gets added before the head, making the new node as the head
*/

struct Stack {
  ListNode* top;
  size_t size;

  Stack() : top(nullptr), size(0) {}
  ~Stack() {
    // Remove all nodes
    ListNode* node = this->top;
    while (node != NULL) {
      ListNode* next_node = node->next;
      delete node;
      node = next_node;
    }
  }

  // Time: O(1)
  void push(int val) {
    ListNode* node = new ListNode(val); // Create a new node
    node->next = this->top; // new node's next points to current top node
    this->top = node;       // set the new node as the top of stack
    this->size++;
  }

  // Time: O(1)
  bool pop() {
    if (this->size == 0) return false;

    ListNode* node = this->top;

    this->top = node->next;
    delete node; // DeAllocate the node
    node = nullptr;
    this->size--;
    if (this->size == 0) this->top = nullptr; // Ensures no memory leak
    return true;
  }

  // Time: O(1)
  ListNode* peek() { return this->top; }

  void print() {
    ListNode* curr = this->top;
    while (curr != NULL) {
      printf("%d -> ", curr->val);
      curr = curr->next;
    }
    printf("NULL\n");
  }
};

//------------------------------------------

int main() {
  Stack* stack = new Stack();
  printf("%p \n", (void*)stack);
  stack->print();

  stack->push(10);
  stack->print();
  stack->push(20);
  stack->print();
  stack->push(30);
  stack->print();

  stack->pop();
  stack->print();

  stack->push(40);
  stack->print();

  printf("%p \n", (void*)stack);
}

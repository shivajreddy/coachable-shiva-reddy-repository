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
#include <cstdarg>
#include <cstddef>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------
// SINGLY LINKED LIST NODE
//------------------------------------------
struct SLLNode {
  int val;
  SLLNode* next;

  SLLNode(int val) : val(val), next(nullptr) {}
  SLLNode(int val, SLLNode* next) : val(val), next(next) {}
};

//------------------------------------------
// SINGLY LINKED LIST
//------------------------------------------
struct SLList {
  SLLNode* head;
  SLLNode* tail;
  size_t size; // total node in list

  SLList() : head(nullptr), tail(nullptr), size(0) {}

  ~SLList() {
    SLLNode* curr = head;
    while (curr != nullptr) {
      SLLNode* next = curr->next;
      delete curr;
      curr = next;
    }
  }

  void push_back(int val) {
    SLLNode* node = new SLLNode(val);
    if (size == 0) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    size++;
  }

  void pop_front() {
    if (size == 0) return;
    SLLNode* target = head;
    head = head->next;
    delete target;
    size--;
    if (size == 1) head->next = nullptr;
  }

  void push_front(int val) {
    SLLNode* node = new SLLNode(val);
    if (size == 0) {
      head = node;
      tail = node;
    } else {
      SLLNode* old_head = head;
      node->next = old_head;
      head = node;
    }
    size++;
  }

  SLLNode* peek_front() { return head; }

  SLLNode* peek_back() { return tail; }
};

//------------------------------------------
// STACK
//------------------------------------------
/*
   Implementation Details:
   - Last In First Out
   - Underlying DataStructure: uses a singly linked list
   - Top item is the head of the linked list
   - New item gets added before the head, making the new node as the head
*/
struct Stack {
  SLLNode* top;
  size_t size;

  Stack() : top(nullptr), size(0) {}

  ~Stack() {
    // Remove all nodes
    SLLNode* node = this->top;
    while (node != NULL) {
      SLLNode* next_node = node->next;
      delete node;
      node = next_node;
    }
  }

  // Time: O(1)
  void push(int val) {
    SLLNode* node = new SLLNode(val); // Create a new node
    node->next = this->top; // new node's next points to current top node
    this->top = node;       // set the new node as the top of stack
    this->size++;
  }

  // Time: O(1)
  bool pop() {
    if (this->size == 0) return false;

    SLLNode* node = this->top;

    this->top = node->next;
    delete node; // DeAllocate the node
    node = nullptr;
    this->size--;
    if (this->size == 0) this->top = nullptr; // Ensures no memory leak
    return true;
  }

  // Time: O(1)
  SLLNode* peek() { return this->top; }

  void print() {
    SLLNode* curr = this->top;
    while (curr != NULL) {
      printf("%d -> ", curr->val);
      curr = curr->next;
    }
    printf("NULL\n");
  }
};

//------------------------------------------
// QUEUE
//------------------------------------------
// - Implement a Queue class with enqueue, dequeue, peek operations all in O(1).
// It should use a singly linked list as well.

// Doubly Linked List Node
struct DLLNode {
  int val;
  DLLNode* next;
  DLLNode* prev;
  DLLNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};

struct DLList {
  public:
  DLLNode* head; // Handle Node
  DLLNode* tail; // Handle Node
  size_t size;   // number of nodes in DLList  excluding handle nodes

  // Constructor
  DLList() {
    head = new DLLNode(-1);
    tail = new DLLNode(-1);
    head->next = tail; // H  -> T
    tail->prev = head; // H <-> T
    size = 0;
  }

  // DeConstructor
  ~DLList() {
    DLLNode* curr = head->next;
    while (curr != nullptr) {
      DLLNode* next = curr->next;
      delete curr;
      curr = next;
    }
    delete head;
    delete tail;
  }

  void push_front(int val) {
    create_and_insert_between_nodes(val, head, head->next);
  }

  void push_back(int val) {
    create_and_insert_between_nodes(val, tail->prev, tail);
  }

  DLLNode* peek_front() {
    if (size == 0) return nullptr;
    return head->next;
  }

  void pop_front() {
    // Remove the node after head node
    remove_next_node(head);
  }

  void pop_back() {
    // node <-> target <-> tail
    auto target = tail->prev;
    auto node = target->prev; // null for an empty list
    remove_next_node(node);
  }

  void print() {
    DLLNode* curr = head->next;
    printf("NULL <-> ");
    for (size_t i = 0; i < size; i++) {
      printf("%d <-> ", curr->val);
      curr = curr->next;
    }
    printf("NULL\n");
  }

  private:
  void create_and_insert_between_nodes(int val, DLLNode* a, DLLNode* b) {
    // Condition: A <-> B
    DLLNode* node = new DLLNode(val); // A <-> B | node
    node->next = b;                   // node  -> B
    b->prev = node;                   // node <-> B
    a->next = node;                   // A  -> node <-> B
    node->prev = a;                   // A <-> node <-> B
    size++;                           // increase size
  }

  private:
  void remove_next_node(DLLNode* node) {
    if (size == 0 || node == nullptr || node->next == tail)
      throw std::runtime_error("ValueError: No nodes in DLL to remove");
    // H ... node <-> target <-> next ... T
    DLLNode* target = node->next; // node <-> target
    DLLNode* next = target->next; // node <-> target <-> next
    node->next = next;            // node  -> next
    next->prev = node;            // node <-> next
    delete target;                // DeAllocate the node
    size--;                       // reduce size
  }
};

struct Queue {
  SLList* sll;
  size_t size;

  Queue() {
    sll = new SLList();
    size = 0;
  }

  ~Queue() { delete sll; }

  bool enque(int val) {
    sll->push_back(val); // could throw false if malloc fails
    size++;
    return true;
  }

  int deque() {
    DLLNode* node = dll->peek_front();
    dll->pop_front();
    size--;
    return node->val;
  }

  void print() { dll->print(); }
};

int main() {
  Stack* stack = new Stack();

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
  printf("-------------------------------\n");

  Queue* q = new Queue();
  q->enque(10);
  q->enque(20);
  q->print();
  q->deque();
  q->enque(30);
  q->print();
}

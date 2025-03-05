#include <cstdarg>
#include <cstddef>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

//------------------------------------------
// SINGLY LINKED LIST NODE
//------------------------------------------
struct SLLNode {
  private:
  int val;

  public:
  SLLNode* next;

  SLLNode(int val) : val(val), next(nullptr) {}
  SLLNode(int val, SLLNode* next) : val(val), next(next) {}

  int get_val() {
    if (this == nullptr)
      throw std::runtime_error("Attempting to access value of a null node");
    return val;
  }
};

//------------------------------------------
// SINGLY LINKED LIST
//------------------------------------------
struct SLList {
  SLLNode *head, *tail;
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

  void print() {
    SLLNode* curr = head;
    for (size_t i = 0; i < size; i++) {
      printf("%d -> ", curr->get_val());
      curr = curr->next;
    }
    printf("NULL  size:%ld\n", size);
  }
};

//------------------------------------------
// STACK
// Q1: - Implement a Stack class with push, pop, peek operations. Everything
// should be implemented in O(1) worst-case runtime using a singly linked list
// to implement it. If you have questions about the requirements you can ask me.
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
      printf("%d -> ", curr->get_val());
      curr = curr->next;
    }
    printf("NULL\n");
  }
};

//------------------------------------------
// QUEUE
// - Q2: Implement a Queue class with enqueue, dequeue, peek operations all in
// O(1). It should use a singly linked list as well.
//------------------------------------------
struct Queue {
  private:
  SLList* sll;

  public:
  size_t size;

  void enque(int val) {
    sll->push_back(val);
    size++;
  }

  int deque() {
    if (size == 0) std::runtime_error("ERROR: Can't deque an empty queue.");
    int res = sll->peek_front()->get_val();
    sll->pop_front();
    size--;
    return res;
  }

  void print() { sll->print(); }

  Queue() : sll(new SLList()), size(0) {}
  ~Queue() { delete sll; } // will call destructor of SLL
};

// Q4: - You are given a pointer/reference to a node (not necessarily the head)
// in a singly linked list. Implement a function to delete that node.
void remove_node(SLLNode* node) {
  if (node == nullptr) return;                  // no node
  if (node->next == nullptr) delete node->next; // last node
  SLLNode* curr = node;
  while (curr != nullptr) {
    SLLNode* temp = curr;
    SLLNode* next = curr->next;
    *temp = *next;
    curr = next;
  }
}

// Q3: - Explain how a singly linked list differs from a doubly linked list.
// Then, implement both. Write a method for removing the last element in both
// implementations.
// Answer: doubly linked points to previous and next, singly list only points to
// next. It's easy to remove a given node in doubly linked list, since we know
// the node the comes before the target node, but in singly linked list, we end
// shifting all the nodes on the right side of target node by 1 to the left
// side.
//-----------------------------------------------------------
// DOUBLE LINKED LIST NODE
//-----------------------------------------------------------
struct DLLNode {
  int val;
  DLLNode* next;
  DLLNode* prev;
  DLLNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};

//-----------------------------------------------------------
// DOUBLE LINKED LIST
//-----------------------------------------------------------
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

// Q5: - Implement a function to reverse a singly linked list iteratively. What
// is the time and space complexity?
SLLNode* reverse_singly_linked_list(SLLNode* head) {
  if (!head) return nullptr;

  SLLNode* curr = head;
  SLLNode* prev = nullptr;

  while (curr != nullptr) {
    SLLNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// Q6: - Write a function that returns the middle node of a linked list in O(n)
// time and O(1) space without counting the length first.
SLLNode* get_middle_node(SLLNode* head) {
  if (!head) return nullptr;
  SLLNode* slow = head;
  SLLNode* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Q7: - Write a function that determines whether a singly linked list
// represents a palindrome. Optimize for O(n) time and O(1) space.
bool is_palindrome(SLLNode* head) {
  if (!head) return true;
  // Get middle node
  SLLNode* slow = head;
  SLLNode* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Reverse the second half of the list
  // the beginning of second half is the node after slow poniter
  SLLNode* second_half_head = slow->next;
  SLLNode* prev = nullptr;
  SLLNode* curr = second_half_head;
  while (curr != nullptr) {
    SLLNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  } // by end of this loop 'prev' is pointing to the head of the reversed list

  SLLNode* first_half_curr = head;
  SLLNode* second_half_curr = prev;
  while (second_half_curr != nullptr) {
    if (first_half_curr->get_val() != second_half_curr->get_val()) return false;
    first_half_curr = first_half_curr->next;
    second_half_curr = second_half_curr->next;
  }
  return true;
}

// Q8: - What is a circular linked list? Implement a method to detect if a given
// linked list is circular.
bool is_circular(SLLNode* head) {
  SLLNode* slow = head;
  SLLNode* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true; // check after moving the pointers
  }
  return false;
}

// Q9: - Write a function that removes duplicates from an unsorted singly linked
// list. What are the time and space tradeoffs?
void remove_duplicates(SLLNode* head) {
  if (!head || !head->next) return; // empty list & single node list
  std::unordered_set<SLLNode*> set;
  SLLNode* curr = head;
  SLLNode* prev = nullptr;
  while (curr != nullptr) {
    if (set.find(curr) != set.end()) {
      prev->next = curr->next; // skip the current node, since its a duplicate
      delete curr;             // free meomry
      curr = prev->next;
    } else {
      set.insert(curr);
      prev = curr;
      curr = curr->next;
    }
  }
}
// Q10: - Given a linked list and a value X, modify the list so that all notes
// less than X come before nodes greater than or equal to X. Maintain the
// relative order of nodes.
void reorder_linked_list(SLLNode* head, int x) {
  if (!head || !head->next) return; // empty, single node list

  SLLNode* left_head = new SLLNode(-1);  // dummy node
  SLLNode* right_head = new SLLNode(-1); // dummy node

  SLLNode* left = left_head;
  SLLNode* right = right_head;

  SLLNode* curr = head;
  while (curr != nullptr) {
    if (curr->get_val() < x) {
      left->next = curr;
      left = curr;
    } else {
      right->next = curr;
      right = curr;
    }
    curr = curr->next;
  }

  right->next = nullptr;   // end the right list
  left->next = right_head; // join left with right
  head = left_head->next;  // update head, because it could've changed
  delete left_head;        // remove dummy nodes
  delete right_head;       // remove dummy nodes
}

// Q11: - How do insertion and deletion differ in a doubly linked list compared
// to a singly linked list? Implement a class for a DoublyLinkedList with insert
// and delete methods.
/*
- DLL: Inserting and deleting is O(1), since every node has both 'prev' & 'next'
- SLL: Insert is O(1), Deleting is O(N). since all the nodes to the right of
       deleted node should be shifted to the left side by 1
*/

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

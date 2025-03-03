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
// linked list to implement it. If you have questions about the requirements you
// can ask me.

#include <stdio.h>
#include <stdlib.h>

// LINKED LIST NODE
//------------------------------------------
typedef struct LinkedListNode {
    int val;
    struct LinkedListNode* next;
} LinkedListNode;

LinkedListNode* create_node(int val) {
    LinkedListNode* node = malloc(sizeof(LinkedListNode));
    if (!node) {
        fprintf(stderr, "ERROR: Failed to malloc for LinkedListNode\n");
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

void remove_node(LinkedListNode* node) {
    // (for now no other clean up operations)
    // DeAllocate the memory for node
    free(node);
}
//------------------------------------------

// STACK
//------------------------------------------
/*
Implementation Details
 - Last In First Out
 - Underlying DataStructure: uses a singly linked list
 - Top item is the head of the linked list
 - New item gets added before the head, making the new node as the head
*/

typedef struct Stack {
    LinkedListNode* top;
    size_t size;
} Stack;

// Time: O(1)
void push(Stack* stack, int val) {
    LinkedListNode* old_top = stack->top;        // node that is top of stack
    LinkedListNode* new_node = create_node(val); // Create a new node
    new_node->next = old_top;
    stack->top = new_node; // set the new node as the top of stack
    stack->size++;
}

// Time: O(1)
void pop(Stack* stack) {
    if (stack->size == 0) return;

    LinkedListNode* node = stack->top;

    stack->top = node->next;
    remove_node(node); // DeAllocate the node
    stack->size--;
}

// Time: O(1)
LinkedListNode* peek(Stack* stack) { return stack->top; }

Stack* create_stack() {
    // Allocate memory for the stack type
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "ERROR: Failed to malloc for Stack");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void remove_stack(Stack* stack) {
    // Remove(DeAllocate) all items in stack
    for (size_t i = 0; i < stack->size; i++) {
        pop(stack);
    }

    // DeAllocate stack
    free(stack);
}

void print_stack(Stack* stack) {
    if (stack->size == 0) return;
    LinkedListNode* curr = stack->top;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}
//------------------------------------------

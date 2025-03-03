"""
- Implement a Stack class with push, pop, peek operations. Everything should be implemented in O(1) worst-case runtime using a singly linked list to implement it. If you have questions about the requirements you can ask me.
- Implement a Queue class with enqueue, dequeue, peek operations all in O(1). It should use a singly linked list as well.
- Explain how a singly linked list differs from a doubly linked list. Then, implement both. Write a method for removing the last element in both implementations.
- You are given a pointer/reference to a node (not necessarily the head) in a singly linked list. Implement a function to delete that node.
- Implement a function to reverse a singly linked list iteratively. What is the time and space complexity?
- Write a function that returns the middle node of a linked list in O(n) time and O(1) space without counting the length first.
- Write a function that determines whether a singly linked list represents a palindrome. Optimize for O(n) time and O(1) space.
- What is a circular linked list? Implement a method to detect if a given linked list is circular.
- Write a function that removes duplicates from an unsorted singly linked list. What are the time and space tradeoffs?
- Given a linked list and a value X, modify the list so that all notes less than X come before nodes greater than or equal to X. Maintain the relative order of nodes.
- How do insertion and deletion differ in a doubly linked list compared to a singly linked list? Implement a class for a DoublyLinkedList with insert and delete methods.
"""

from typing import Optional

# Implement a Stack class with push, pop, peek operations. Everything should be implemented in O(1) worst-case runtime using a singly linked list to implement it. If you have questions about the requirements you can ask me.
class Node:
    def __init__(self, value: int) -> None:
        self.value: int = value
        self.next: Optional[Node] = None

class Stack:
    def __init__(self) -> None:
        self.head: Optional[Node] = None
        self.size: int = 0
    
    def push(self, value):
        """
        Add an element to the top of the stack.
        Time complexity: O(1)
        """
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.size += 1
    
    def pop(self):
        """
        Remove and return the element at the top of the stack.
        Time complexity: O(1)
        Raises: Exception if stack is empty
        """

        if self.is_empty():
            raise Exception("Stack is empty")

        
        popped_value = self.head.value
        self.head = self.head.next
        self.size -= 1
        return popped_value
    
    def peek(self):
        """
        Return the element at the top of the stack without removing it.
        Time complexity: O(1)
        Raises: Exception if stack is empty
        """
        if self.is_empty():
            raise Exception("Stack is empty")
        
        return self.head.value
    
    def is_empty(self):
        """
        Check if the stack is empty.
        Time complexity: O(1)
        """
        return self.head is None
    
    def get_size(self):
        """
        Return the number of elements in the stack.
        Time complexity: O(1)
        """
        return self.size



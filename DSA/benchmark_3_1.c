/*
Implement Hashmap
 - The constructor should specify a max size for the hashmap.
 - Implement get/put operations.
 - Implement your own hashfunction.
 - You can assume the keys are strings and values are integers.
 - Please implement the collision handling using separate chaining (linked
   lists)
 - Do not worry about resizing for now.
 - If you exceed the max size, just reject the new value and print an error.
 - Write unit tests for this to verify that it works.

 - Modify the FixedHashMap implementation to use open addressing (linear
   probing) instead of separate changing.
    - Implement put, get, remove. If a collision occurs, probe sequentially
      until an empty slot is found.
 - Extend your Hashmap to track the smallest and largest keys efficiently
   without scanning all keys on each request.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 256
#define TABLE_SIZE 8

typedef struct Pair {
  char key[MAX_KEY_LEN];
  int val;
} Pair;

typedef struct Node {
  struct Pair val;
  struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];
size_t size = 0;

void init_hashmap() {
  // Initialize an empty hash table with empty nodes
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
}

unsigned int hash(char* key) {
  unsigned int hash_val = 0;
  for (int i = 0; i < strlen(key); i++) {
    hash_val += key[i];
    hash_val = (hash_val * key[i]) % TABLE_SIZE;
  }
  return hash_val;
}

void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Node* node = hash_table[i];
    if (node == NULL) {
      printf("[NULL]");
    } else {
      Node* curr = hash_table[i];
      printf("[");
      while (curr != NULL) {
        printf("%s-%i->", curr->val.key, curr->val.val);
        curr = curr->next;
      }
      printf("NULL]");
    }
  }
  printf("\n");
}

Node* get(char* key) {
  int index = hash(key);
  printf("trying to get %s %d\n", key, index);
  Node* node = hash_table[index];
  if (node == NULL) {
    printf("ERROR:: key:%s NOT FOUND\n", key);
    return NULL;
  }

  // Follow chain
  Node* curr = node;
  while (curr != NULL) {
    char* key_name = curr->val.key;
    char* target_name = key;
    if (*key_name == *target_name) {
      // printf("equal::%s %s", key_name, target_name);
      return curr;
    }
    curr = curr->next;
  }

  printf("ERROR:: key:%s NOT FOUND\n", key);
  return NULL;
}

bool put(char* key, int val) {
  // Check for current size
  if (size == TABLE_SIZE) {
    printf("ERROR: hash_table is full\n");
    return false;
  }

  Pair pair;
  strncpy(pair.key, key, MAX_KEY_LEN);
  pair.val = val;

  Node* new_node = malloc(sizeof(Node));
  new_node->val = pair;
  new_node->next = NULL;

  int index = hash(pair.key);

  // No-Collision
  Node* curr_node = hash_table[index];
  if (curr_node == NULL) {
    hash_table[index] = new_node;
    size++;
    return true;
  }

  // Collision. Handle using linear propogation
  while (curr_node->next != NULL) {
    curr_node = curr_node->next;
  }
  curr_node->next = new_node;
  size++;
  return true;
}

void uninit_hashmap() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Node* node = hash_table[i];
    if (node != NULL) {
      free(node);
    }
  }
}

int main() {
  printf("TESTING HASHMAP :: STARTED\n");
  init_hashmap();
  print_table();

  put("Jacob", 21);
  put("jacob", 21);
  put("Natalie", 21);
  put("Sara", 21);
  put("Mpho", 21);
  put("Tebogo", 21);
  put("Ron", 21);
  put("Jane", 21);
  put("Maren", 21);
  put("Bill", 21);

  print_table();
  get("jacob");
  get("jacob");

  uninit_hashmap();
  printf("TESTING HASHMAP :: FINISHED\n");
  return EXIT_SUCCESS;
}

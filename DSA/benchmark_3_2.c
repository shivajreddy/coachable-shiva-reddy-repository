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

Pair* hash_table[TABLE_SIZE];
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
    Pair* pair = hash_table[i];
    if (pair == NULL) {
      printf("[NULL]");
    } else {
      printf("[%s-%d]", pair->key, pair->val);
    }
  }
  printf("\n");
}

Pair* get(char* key) {
  int index = hash(key);
  printf("trying to get %s %d\n", key, index);
  Pair* pair = hash_table[index];
  if (pair == NULL) {
    printf("ERROR:: key:%s NOT FOUND\n", key);
    return NULL;
  }

  int start_index = index;
  int curr_index = index;
  // Follow the entire table
  do {
    if (*(hash_table[curr_index]->key) == *key) {
      return hash_table[curr_index];
    }
    curr_index = (curr_index + 1) % TABLE_SIZE;
  } while (curr_index != start_index);

  printf("ERROR:: key:%s NOT FOUND\n", key);
  return NULL;
}

bool put(char* key, int val) {
  // Check for current size
  // printf("\nPUT: %s\n", key);
  if (size == TABLE_SIZE) {
    printf("ERROR: hash_table is full\n");
    return false;
  }

  Pair* pair = malloc(sizeof(Pair));
  strncpy(pair->key, key, MAX_KEY_LEN);
  pair->val = val;

  int index = hash(key);

  // Linear Probing
  int curr_index = index;
  while (hash_table[curr_index] != NULL) {
    // printf("key=%s curr_index:%d\n", key, curr_index);
    // if the key already exists, update the value
    if (strncmp(hash_table[curr_index]->key, key, MAX_KEY_LEN) == 0) {
      hash_table[curr_index]->val = val;
      free(pair);
      return true;
    }
    curr_index = (curr_index + 1) % TABLE_SIZE;
  }

  // Insert the new pair
  hash_table[curr_index] = pair;
  size++;
  return true;
}

void uninit_hashmap() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Pair* pair = hash_table[i];
    if (pair == NULL) continue;
    free(pair);
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

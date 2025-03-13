/*
Implement Hashmap
 - The constructor should specify a max size for the hashmap.
 - Implement get/put operations.
 - Implement your own hashfunction. Don’t worry too much about getting an ideal
   hash function, anything to start will work.
 - You can assume the keys are strings and values are integers. Mention this in
   the typing of your functions.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 256
#define TABLE_SIZE 10

typedef struct HashMap {
  char* key;
  int val;
} HashMap;

typedef struct Pair {
  char key[MAX_KEY_LEN];
  int val;
} Pair;

HashMap* init_hashmap() {
  HashMap* hm = malloc(sizeof(HashMap));
  if (!hm) {
    printf("Allocating for hashmap failed\n");
    return NULL;
  }
  return hm;
}

unsigned int hash(char* key) {
  unsigned int hash_val = 0;
  for (int i = 0; i < strlen(key); i++) {
    hash_val += key[i];
    hash_val = (hash_val * key[i]) % TABLE_SIZE;
  }
  return hash_val;
}

int main() {
  printf("Jacob => %u\n", hash("Jacob"));
  printf("Natalie => %u\n", hash("Natalie"));
  printf("Sara => %u\n", hash("Sara"));
  printf("Mpho => %u\n", hash("Mpho"));
  printf("Tebogo => %u\n", hash("Tebogo"));
  printf("Ron => %u\n", hash("Ron"));
  printf("Jane => %u\n", hash("Jane"));
  printf("Maren => %u\n", hash("Maren"));
  printf("Bill => %u\n", hash("Bill"));

  printf("TESTING HASHMAP :: STARTED\n");
  HashMap* hm = init_hashmap();
  if (!hm) {
    printf("Allocating for hashmap failed\n");
    return EXIT_FAILURE;
  }
  printf("TESTING HASHMAP :: FINISHED\n");
  return EXIT_SUCCESS;
}

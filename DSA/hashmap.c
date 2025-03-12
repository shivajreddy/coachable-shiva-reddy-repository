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

typedef struct HashMap {
  char* key;
  int val;
} HashMap;

HashMap* create_hashmap() {
  HashMap* hm = malloc(sizeof(HashMap));
  if (!hm) {
    printf("Allocating for hashmap failed\n");
    return NULL;
  }
  return hm;
}

int main() {
  HashMap* hm = create_hashmap();
  if (!hm) {
    printf("Allocating for hashmap failed\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

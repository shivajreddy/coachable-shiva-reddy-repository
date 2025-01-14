/*
MinHeap implementation
key  : int
value: [int, int] 
*/

#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

typedef struct {
  int** array;
  int size;
  int capacity;
} MinHeap;

MinHeap* create_min_heap(int capacity) {
  MinHeap* mh = malloc(sizeof(MinHeap));
  mh->array = malloc((sizeof(int) * 2) * capacity);
  mh->size = 0;
  mh->capacity = capacity;
  return mh;
}

void free_heap(MinHeap* mh) {
  // Go over the array and clear all tuples
  for (int i = 0; i < mh->size; i++) {
    int* curr = mh->array[i];
    free(curr);
  }
  // Free the array itself
  free(mh);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insert_item(MinHeap* mh, int* arr) {
  // Reached Max. Capacity
  if (mh->size == mh->capacity)
    return;

  // Insert at end
  mh->size++;
  int i = mh->size - 1;
  mh->array[i] = arr;

  // Swip Up
  while (1) {
    if (i <= 0)
      break;
    int* parent = mh->array[PARENT(i)];
    int* curr = mh->array[i];
    if (parent[0] > curr[0])
      break;
    swap(mh->array[i]);
    i = PARENT(i);
  }
  while (i != 0 && mh->array[PARENT(i)][0] > mh->array[i][0]) {
    swap(mh->array[i], mh->array[PARENT(i)]);
    i = PARENT(i);
  }
}

void heapify_down() {}

int* pop(MinHeap* mh) {
  return NULL;
}

int main() {
  printf("tuple %ld bytes\n", sizeof(int*));
  printf("MinHeap %ld bytes\n", sizeof(MinHeap));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

typedef struct {
  int* array;
  int size;
  int capacity;
} MinHeap;

MinHeap* create_min_heap(int capacity) {
  MinHeap* mh = malloc(sizeof(MinHeap));
  mh->array = malloc(capacity * sizeof(int));
  mh->size = 0;
  mh->capacity = capacity;
  return mh;
}

void swap(int* a, int* b) {
  int a_value = *a;
  *a = *b;
  *b = a_value;
}

void heapify_down(MinHeap* mh, int idx) {
  int smallest = idx;
  int left = LEFT(idx);
  int right = RIGHT(idx);

  if (left < mh->size && mh->array[left] < mh->array[smallest]) {
    smallest = left;
  }
  if (smallest != idx) {
    swap(&mh->array[idx], &mh->array[smallest]);
    heapify_down(mh, smallest);
  }
}

void insert_key(MinHeap* mh, int key) {
  // Reached maximum capacity
  if (mh->size == mh->capacity) {
    // printf("Overflow: Could not insert key\n");
    return;
  }

  // Insert at end
  mh->size++;
  int i = mh->size - 1;
  mh->array[i] = key;

  // Bubble up
  while (i != 0 && mh->array[PARENT(i)] > mh->array[i]) {
    swap(&mh->array[i], &mh->array[PARENT(i)]);
    i = PARENT(i);
  }
}

// Extracts the minimum item form heap
int pop(MinHeap* mh) {
  if (mh->size <= 0) {
    return -1;
  };
  if (mh->size == 1) {
    mh->size--;
    return mh->array[0];
  }
  int root = mh->array[0];
  mh->array[0] = mh->array[mh->size - 1];
  mh->size--;
  heapify_down(mh, 0);
  return root;
}

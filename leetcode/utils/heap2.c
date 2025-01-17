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

MinHeap* heapify(int* arr, int size, int capacity);
void heapify_down(MinHeap* mh, int idx);

void print_minheap(MinHeap* mh) {
  int** arr = mh->array;
  for (int i = 0; i < mh->size; i++) {

    int* item = arr[i];
    printf("%d-%d ", item[0], item[1]);
  }
  puts("");
}

MinHeap* create_min_heap(int capacity) {
  MinHeap* mh = malloc(sizeof(MinHeap));
  if (!mh)
    return NULL;

  // Create 2d-array, where no.of_cols=2, no.of_rows=capacity
  int** arr = (int**)malloc(capacity * sizeof(int*));
  if (!arr) {

    free(mh);
    return NULL;
  }

  for (int i = 0; i < capacity; i++) {
    arr[i] = (int*)malloc(2 * sizeof(int));

    if (!arr[i]) {
      // Clean up previously allocated memory
      for (int j = 0; j < i; j++) {
        free(arr[j]);
      }
      free(arr);
      free(mh);
      return NULL;
    }
  }

  mh->array = arr;
  mh->size = 0;
  mh->capacity = capacity;
  return mh;
}

MinHeap* heapify(int* arr, int size, int capacity) {
  if (size > capacity)
    return NULL;

  MinHeap* mh = create_min_heap(capacity);
  if (!mh)
    return NULL;

  mh->size = size;
  for (int i = 0; i < size; i++) {
    mh->array[i][0] = arr[i];
    mh->array[i][1] = i;
  }

  // Heapify from bottom-up
  for (int i = (size / 2) - 1; i >= 0; i--) {
    heapify_down(mh, i);
  }

  return mh;
}

void free_heap(MinHeap* mh) {
  if (!mh)
    return;

  // Go over the array and clear all tuples
  for (int i = 0; i < mh->capacity; i++)  // Changed from size to capacity
    free(mh->array[i]);

  // Free the array itself
  free(mh->array);
  free(mh);
}

void swap_items(MinHeap* mh, int i, int j) {
  int* temp = mh->array[i];
  mh->array[i] = mh->array[j];
  mh->array[j] = temp;
}

void insert_item(MinHeap* mh, int value, int index) {
  // Reached Max. Capacity
  if (!mh || mh->size >= mh->capacity)
    return;

  // Create new item
  int* new_item = (int*)malloc(2 * sizeof(int));
  if (!new_item)
    return;

  new_item[0] = value;
  new_item[1] = index;

  // Insert at end
  int i = mh->size;
  mh->array[i] = new_item;
  mh->size++;

  // Sift Up
  while (i > 0 && mh->array[PARENT(i)][0] > mh->array[i][0]) {
    swap_items(mh, i, PARENT(i));

    i = PARENT(i);
  }
}

void heapify_down(MinHeap* mh, int idx) {
  int smallest = idx;
  int left = LEFT(idx), right = RIGHT(idx);

  if (left < mh->size && mh->array[left][0] < mh->array[smallest][0])
    smallest = left;

  if (right < mh->size && mh->array[right][0] < mh->array[smallest][0])
    smallest = right;

  if (smallest != idx) {
    swap_items(mh, idx, smallest);
    heapify_down(mh, smallest);
  }
}

int* pop(MinHeap* mh) {
  if (!mh || mh->size <= 0)
    return NULL;

  int* root = mh->array[0];

  if (mh->size > 1) {
    mh->array[0] = mh->array[mh->size - 1];
    heapify_down(mh, 0);
  }

  mh->size--;
  return root;
}

int main() {
  // printf("PROGRAM START\n");

  int arr[5] = {21, 31, 88, 123, 87};

  // Heapify a given array into the MinHeap
  MinHeap* mh = heapify(arr, 5, 5);
  printf("mh.size = %d \n", mh->size);
  print_minheap(mh);

  // Pop all items
  while (mh->size > 0) {
    int* item = pop(mh);
    printf("%d %d\n", item[0], item[1]);
  }

  free_heap(mh);

  return 0;
}

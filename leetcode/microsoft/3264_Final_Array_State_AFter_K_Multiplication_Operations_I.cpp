// 3264. Final Array State AFter K Multiplication Operations I
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getFinalState(int* nums, int numsSize, int k, int multiplier,
                   int* returnSize) {

  // Create a Min-Heap of nums along with their input
  void* min_heap = ();
}

void print_array(int* arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i < size - 1)
      printf(",");
  }

  printf("]\n");
}

void run_test(int* nums, int nums_size, int k, int multiplier, int* expected) {
  int return_size;
  int* result;
  result = getFinalState(nums, nums_size, k, multiplier, &return_size);

  printf("Input: nums = ");
  print_array(nums, nums_size);
  printf("k = %d multiplier = %d\n", k, multiplier);
  printf("Expected: ");
  print_array(expected, nums_size);
  printf("Received: ");
  print_array(result, nums_size);

  free(result);
}

int main() {
  {  // Test case 1
    puts("TEST CASE 1");
    int nums[] = {2, 1, 3, 5, 6};
    int expected[] = {8, 4, 6, 5, 6};
    run_test(nums, 5, 5, 2, expected);
    puts("");
  }

  {  // Test case 2
    puts("TEST CASE 2");
    int nums[] = {1, 2};
    int expected[] = {16, 8};
    run_test(nums, 2, 3, 4, expected);
    puts("");
  }

  {  // Test case 3
    puts("TEST CASE 3");
    int nums3[] = {};
    int expected3[] = {};
    run_test(nums3, 0, 5, 2, expected3);
    puts("");
  }

  {  // Test case 4
    puts("TEST CASE 4");
    int nums4[] = {3};
    int expected4[] = {12};
    run_test(nums4, 1, 2, 2, expected4);
    puts("");
  }

  {  // Test case 5: k = 0
    puts("TEST CASE 5");
    int nums5[] = {1, 2, 3};
    int expected5[] = {1, 2, 3};
    run_test(nums5, 3, 0, 2, expected5);
    puts("");
  }
}

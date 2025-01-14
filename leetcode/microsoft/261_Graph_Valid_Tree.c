// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int size) {
  int i = 0;
  while (i < size)
    printf("%d ", arr[i++]);
}

void free_edges(int** edges, int edgesSize) {
  for (int i = 0; i < edgesSize; i++)
    free(edges[i]);
  free(edges);
  edges = NULL;
}

bool validTree(int n, int** edges, int edgesSize, int* edgesColSize) {

  return false;
}

int main() {
  // Test Case 1
  {
    int n = 5;
    int edgesSize = 4;
    int edgesColSizeValue = 2;
    int* edgesColSize = &edgesColSizeValue;

    // Allocate Memory
    int** edges = (int**)malloc(sizeof(int*) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
      edges[i] = (int*)malloc(sizeof(int) * (*edgesColSize));
    }

    // Fill the edges array
    edges[0][0] = 0;
    edges[0][1] = 1;
    edges[1][0] = 0;
    edges[1][1] = 2;
    edges[2][0] = 0;
    edges[2][1] = 3;
    edges[3][0] = 1;
    edges[3][1] = 4;

    bool result = validTree(n, edges, edgesSize, edgesColSize);

    // Free Memory
    free_edges(edges, edgesSize);

    puts("");
    puts("TEST CASE :: 1");
    printf("Expected: %d\n", true);
    printf("Result  : %d\n", result);
    puts("");
  }
  // Test Case 2
  {
    int n = 5;
    int edgesSize = 5;
    int edgesColSizeValue = 2;
    int* edgesColSize = &edgesColSizeValue;

    // Allocate Memory
    int** edges = (int**)malloc(sizeof(int*) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
      edges[i] = (int*)malloc(sizeof(int) * (*edgesColSize));
    }

    // Fill the edges array
    edges[0][0] = 0;
    edges[0][1] = 1;
    edges[1][0] = 1;
    edges[1][1] = 2;
    edges[2][0] = 2;
    edges[2][1] = 3;
    edges[3][0] = 1;
    edges[3][1] = 3;
    edges[4][0] = 1;
    edges[4][1] = 4;

    bool result = validTree(n, edges, edgesSize, edgesColSize);

    // Free Memory
    free_edges(edges, edgesSize);

    puts("");
    puts("TEST CASE :: 1");
    printf("Expected: %d\n", true);
    printf("Result  : %d\n", result);
    puts("");
  }
  return 0;
}

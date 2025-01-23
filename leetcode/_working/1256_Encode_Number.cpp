#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::string;

char* encode(int num) {

  int n = num + 1;
  int len = 0;
  int temp = n;

  /*
  // Can also use 'log' to find the length of binary number
  // include math lib and link for compiling
  int len = (int)floor(log2(n)) + 1;  
  */

  // Calculate binary length, by shifting bits, until no bits
  while (temp > 0) {
    len++;
    temp >>= 1;  // move to next bit
  }
  // printf("len: %d\n", len);

  // intentionally not allocating extra for null byte
  // since we skip one byte to replicate the magic fn output
  char* result = (char*)malloc(len);
  if (result == NULL)
    return NULL;  // failed to allocate memory

  // convert to binary string, skipping first digit
  for (int i = len - 2; i >= 0; i--) {
    result[i] = (n & 1) + '0';
    printf("i:%d, result: %s\n", i, result);
    n >>= 1;
  }

  result[len - 1] = '\0';
  return result;
}

class Solution {
 public:
  string encode(int num) {
    string result = "";
    return result;
  }
};

int main() {

  auto run_test = [](Solution sol, int num, string expected) {
    std::cout << "Num: " << num << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Received: " << sol.encode(num) << "\n" << std::endl;
  };

  Solution sol;

  run_test(sol, 1, "1000");
  run_test(sol, 2, "1000");
  run_test(sol, 23, "1000");

  return 0;
}

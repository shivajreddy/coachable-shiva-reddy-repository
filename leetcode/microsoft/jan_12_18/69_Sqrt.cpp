// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx

#include <cmath>
#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  int mySqrt(int x) {
    // Edge case
    if (x < 2)
      return x;

    // Largest value could only be x/2
    long left = 1, right = x / 2;

    // Binary search
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long square = mid * mid;

      if (square == x)
        return static_cast<int>(mid);

      if (square < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return static_cast<int>(right);
  }
};

int main() {
  Solution sol;
  auto run_test = [](Solution sol, int num) {
    std::cout << num << std::endl;
    std::cout << sol.mySqrt(num) << "\n" << std::endl;
  };

  // Test 1
  run_test(sol, 9);
  // Test 2
  run_test(sol, 8);
  // Test 3
  run_test(sol, 0);
  // Test 4
  run_test(sol, 1);

  return 0;
}

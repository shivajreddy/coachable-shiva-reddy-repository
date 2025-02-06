#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

/*
Time : 2^n
  */
class Solution {

 public:
  string countAndSay(int n) {
    // Base condition
    if (n == 1)
      return "1";

    string prev = countAndSay(n - 1);
    string result = "";

    for (int i = 0; i < prev.length(); i++) {
      int count = 1;
      // count all same chars
      // iterate from 0 to N-1 (N is the last index)
      // as long as current char is same as the next char
      while (i + 1 < prev.length() && prev[i] == prev[i + 1]) {
        count++;
        i++;
      }
      result += to_string(count) + prev[i];
    }
    return result;
  }
};

void runTest(string testName, int input, string expectedOutput) {
  Solution sol;
  string result = sol.countAndSay(input);
  cout << testName << ": ";
  if (result == expectedOutput) {
    cout << "PASSED" << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "  Expected: " << expectedOutput << endl;
    cout << "  Got: " << result << endl;
  }
}

void runTests() {
  cout << "Running Count and Say Tests..." << endl;
  cout << "--------------------------------" << endl;

  // Basic test cases from problem description
  runTest("Test 1 (Base Case)", 1, "1");
  runTest("Test 2", 2, "11");
  runTest("Test 3", 3, "21");
  runTest("Test 4", 4, "1211");

  // Additional test cases
  runTest("Test 5", 5, "111221");
  runTest("Test 6", 6, "312211");
  runTest("Test 7", 7, "13112221");

  // Performance test for a larger input
  cout << "\nPerformance Test:" << endl;
  cout << "Testing n = 20..." << endl;

  auto start = chrono::high_resolution_clock::now();
  Solution sol;
  sol.countAndSay(20);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

  cout << "Time taken: " << duration.count() << " milliseconds" << endl;
}

int main() {
  runTests();
  return 0;
}

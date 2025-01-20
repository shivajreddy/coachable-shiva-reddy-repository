// 43. Multiple Strings
// https://leetcode.com/problems/multiply-strings/description

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void print_vec(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  printf("\n");
}

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    int len1 = num1.size(), len2 = num2.size();

    vector<int> result(len1 + len2, 0);

    // iterate right to left of num1
    for (int i = len1 - 1; i >= 0; i--) {
      int dig1 = num1[i] - '0';  // char to int
      // iterate right to left of num2
      for (int j = len2 - 1; j >= 0; j--) {
        int dig2 = num2[j] - '0';  // char to int
        result[i + j + 1] += dig1 * dig2;
      }
    }

    print_vec(result);

    for (int i = result.size() - 1; i > 0; i--) {
      result[i - 1] += result[i] / 10;
      result[i] %= 10;
    }
    int start_idx = result[0] == 0 ? 1 : 0;

    string result_str;

    for (int i = start_idx; i < result.size(); i++) {
      char dig = '0' + result[i];  // int to char
      result_str += dig;
    }

    return result_str;
  }
};

int main() {

  Solution sol;

  auto run_test = [](Solution sol, string num1, string num2) {
    string output = sol.multiply(num1, num2);
    cout << "Input: num1=" << num1 << "  num2=" << num2 << endl;
    cout << "Output:" << output << "\n" << endl;
  };

  // Test 1
  {
    string num1 = "2";
    string num2 = "3";
    run_test(sol, num1, num2);
  }

  // Test 2
  {
    string num1 = "123";
    string num2 = "456";
    run_test(sol, num1, num2);
  }

  return 0;
}

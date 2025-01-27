// 71. Simplify Path
// https://leetcode.com/problems/simplify-path

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string simplifyPath(string path) {

    vector<string> stack;
    // process the path string
    string component;
    std::stringstream ss(path);

    while (getline(ss, component, '/')) {
      if (component == "" || component == ".")
        continue;  // ignore empty compoenents

      else if (component == "..") {
        // get the last valid directory from the stack
        if (!stack.empty()) {
          stack.pop_back();
        }

      } else {
        stack.push_back(component);
      }
    }

    if (stack.empty()) {
      return "/";
    }

    string canonical_path;
    for (const string& dir : stack) {
      canonical_path += "/" + dir;
    }
    return canonical_path;
  }
};

int main() {

  auto run_test = [](Solution sol, string path, string expected) {
    std::cout << "EXPECTED: " << expected << "\n";
    std::cout << "RECEIVED: " << sol.simplifyPath(path);
    std::cout << "\n" << std::endl;
  };

  Solution sol;

  run_test(sol, "/home/", "/home");
  run_test(sol, "/home//foo/", "/home/foo");
  run_test(sol, "/home/user/Documents/../Pictures", "/home/user/Pictures");

  return 0;
}

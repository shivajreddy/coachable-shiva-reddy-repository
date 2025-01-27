// 1762. Buildings With an Ocean View
// https://leetcode.com/problems/buildings-with-an-ocean-view

#include <iostream>
#include <vector>

using std::vector;

void print_vector(const vector<int>& v) {
  for (int num : v)
    std::cout << num << " ";
  std::cout << std::endl;
}

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {

    int n = heights.size();  // total builidings

    // Create a vector of bools, where last building is always true
    vector<int> bool_array(n);
    bool_array.back() = 1;

    int max_height = heights.back();
    for (int i = n - 2; i >= 0; i--) {
      int height = heights[i];
      if (height > max_height)
        bool_array[i] = 1;

      // update the tallest building encountered
      max_height = std::max(max_height, height);
    }

    // Find the building indexes that can see ocean, based of boolean array
    vector<int> result;
    for (int i = 0; i < n; i++) {
      if (bool_array[i] == 1)
        result.push_back(i);
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<int> buildings;
  vector<int> expected;

  auto run_tests = [](Solution sol, vector<int> buildings,
                      vector<int> expected) {
    std::cout << "EXPECTED: ";
    print_vector(expected);
    vector<int> result = sol.findBuildings(buildings);
    std::cout << "RESULT  : ";
    print_vector(result);
    std::cout << "\n";
  };

  {
    buildings = {4, 2, 3, 1};
    expected = {0, 2, 3};
    run_tests(sol, buildings, expected);
  }

  {
    buildings = {4, 3, 2, 1};
    expected = {0, 1, 2, 3};
    run_tests(sol, buildings, expected);
  }

  {
    buildings = {1, 3, 2, 4};
    expected = {3};
    run_tests(sol, buildings, expected);
  }

  return 0;
}

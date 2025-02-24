// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/description/

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
  bool operator()(vector<int>& a, const vector<int>& b) { return a[0] >= b[0]; }
};

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {

    // Store all the intervals in a min-heap
    // Time: O(n log n)  Space: O(n)
    priority_queue<vector<int>, vector<vector<int>>, Compare> min_heap;
    for (vector<int> interval : intervals) {
      min_heap.push(interval);
    }

    vector<vector<int>> result;
    while (!min_heap.empty()) {
      vector<int> interval = min_heap.top();
      min_heap.pop();
      int start = interval[0], end = interval[1];
      if (!result.empty() && result.back()[1] >= start) {
        result.back()[1] = max(result.back()[1], end);
      } else {
        result.push_back({start, end});
      }
    }

    return result;
  }
};

// HELPERS
void print_intervals(vector<vector<int>>& intervals) {
  for (vector<int> v : intervals) {
    printf("[%d, %d] ", v[0], v[1]);
  }
  printf("\n");
}

int main() {
  auto test = [](Solution sol, vector<vector<int>>& intervals,
                 vector<vector<int>>& expected) {
    printf("EXPECTED: ");
    print_intervals(expected);
    printf("RECEIVED: ");
    auto result = sol.merge(intervals);
    print_intervals(result);
    printf("\n");
  };

  Solution sol;
  vector<vector<int>> intervals, expected;

  intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  expected = {{1, 6}, {8, 10}, {15, 18}};
  test(sol, intervals, expected);

  intervals = {{1, 4}, {4, 5}};
  expected = {{1, 5}};
  test(sol, intervals, expected);

  return 0;
}

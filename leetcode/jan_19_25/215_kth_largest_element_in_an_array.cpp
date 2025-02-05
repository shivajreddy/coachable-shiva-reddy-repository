// 215. K'th Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array

#include <functional>
#include <vector>

using std::vector;

/*
build a min-heap, largest item is always on top
pop k items, the last k'th item that was popped is the result

Time:
- build min-heap: O(n)
- popping: k. log(n).  worst case: n.log(n)
Space: 
- mih-heap: O(n)

*/

#include <queue>
#include <vector>

using std::greater;
using std::priority_queue;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    // Create a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Keep only k largest elements in the heap
    for (int num : nums) {
      minHeap.push(num);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    // The top element will be the kth largest
    return minHeap.top();
  }
};

// 1570. Dot Product of Two Sparrse Vectors
// https://leetcode.com/problems/dot-product-of-two-sparse-vectors

#include <vector>

using std::pair;
using std::vector;

/*
Observations:
- since in  sparse vector most of the numbers are zero, we build the
  SparseVector such that we only store the numbers that are not zero.
- but we also need their indexes, so we can have a pair of non-zero number
  and it's index
 - Implement efficient dot product using two-pointers

Time: 
 - Construction: O(n) where n is the length of input vector
 - Dot Product: O(k1 + k2) where k1, k2 are counts of non-zero elements
Space Complexity:
 - O(k) where k is the count of non-zero elements
 - In worst case O(n) if all elements are non-zero

 */

class SparseVector {
 private:
  vector<pair<int, int>> sparse_vec;  // {value, index} pairs

 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        sparse_vec.push_back({nums[i], i});
      }
    }
  }

  int dotProduct(SparseVector& vec) {
    int result = 0;
    int i = 0, j = 0;

    // Two-pointer approach to calculate dot product
    while (i < sparse_vec.size() && j < vec.sparse_vec.size()) {
      if (sparse_vec[i].second < vec.sparse_vec[j].second) {
        i++;
      } else if (sparse_vec[i].second > vec.sparse_vec[j].second) {
        j++;
      } else {  // Indices match
        result += sparse_vec[i].first * vec.sparse_vec[j].first;
        i++;
        j++;
      }
    }

    return result;
  }
};

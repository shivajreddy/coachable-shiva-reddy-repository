// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int result = 0;

    unordered_map<int, int> hm = {{0, 1}};

    int prefix_sum = 0;
    for (int num : nums) {
      prefix_sum += num;

      int target = prefix_sum - k;
      if (hm.count(target) > 0) {
        result += hm[target];
      }

      // add current prefix to hashmap
      hm[prefix_sum]++;
    }

    return result;
  }
};

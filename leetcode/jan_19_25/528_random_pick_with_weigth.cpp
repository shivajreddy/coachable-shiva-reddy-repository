// 528. Random Pick with Weigth
// https://leetcode.com/problems/random-pick-with-weight

#include <cstdlib>
#include <vector>

using std::vector;

/*
Example: [3, 5]
[ 3 5 ]  <- array
  0 1    <- index

  3 8    <- prefix-sum-array

So for this input, the problem says that you should 
pick index-0: 3 out of 8 times
pick index-1: 5 out of 8 times

1   2   3   4   5   6   7   8   <- all possible weights
3   3   3   8   8   8   8   8   <- prefix
0   0   0   1   1   1   1   1   <- index of the above prefix

- As you can see, if we have a prefix array, and we know the maximum
  weight which the last item in the prefix array.
- All the possible weights are 1..total_weight
- Now pick a random weight out of all the possible weights
- For this randomly picked weigth, find the first prefix that is 

  >= to the randomly picked weight

  In the above example: you could randomly pick anything in b/w 1..8
  And if you think about it, for numbers 1,2,3 your prefix is 3 because
  that is the first prefix >= 1 or 2 or 3
  Similarly for any random number picked b/w  4,5,6,7,8 the prefix would
  be 8.
  And as you can see now:
    3/8 would pick the prefix 3 which maps to idx:0
    5/8 would pick the prefix 8 which maps to idx:1

- so ultimately, having a prefix array, and randomly picking a weight(r)
  among all the possible weights and finding the 1st prefix >= r, will
  lead result in randomly picking an index based on the indexe's weight


Step-by-Step Process:

1. Compute the Prefix Sum Array:
   - Start with the first weight: The first weight is 1.
   - Add the next weight to the cumulative sum:  
     1 + 3 = 4.
   - Prefix Sum Array:  
     The resulting prefix sum array is [1, 4].


2. Generate a Random Number:
   - Total sum of weights: The total sum of the weights is 4.
   - Generate a random integer `r` in the range [1, 4] (inclusive).
   - Possible Values of `r`:  
     `r` could be 1, 2, 3, or 4.

3. Map the Random Number to an Index Using Binary Search:
   - Goal: Find the smallest index in the prefix sum array where the 
     prefix sum is greater than or equal to `r`. This index corresponds to the
     selected weight.

4. Performing Binary Search:
    left = 0
    right = total_weight - 1
    target = random-weight
    condition, find the value that is >= target

5. Selected Index:
   - The final value of `left` is 1, so the selected index is 1.

6. Mapping the Random Number to the Index:
   - If `r = 4`: The binary search identifies index 1 as the correct position.

   - Interpretation:  
     Index 1 in the original weights array [1, 3] corresponds to the weight 3.


Time & Space:
  Time: 
      Initialization: O(N)
      Pick-Index: O(log.N) since we binary search
  Space: O(N) for the prefix array

*/

class Solution {
 private:
  vector<int> prefix_sum;
  int total_weight;

 public:
  Solution(vector<int>& w) {
    prefix_sum = w;
    // Build prefix sum array
    for (int i = 1; i < w.size(); i++) {
      prefix_sum[i] += prefix_sum[i - 1];
    }
    total_weight = prefix_sum.back();  // Last element has total sum
  }

  int pickIndex() {
    // Generate random number in range [0, total_weight-1]
    int target = rand() % total_weight;

    // Binary search to find the first number greater than target
    int left = 0, right = prefix_sum.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (prefix_sum[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};

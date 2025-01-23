#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
Observations:
1. Forming the first lexicographical number for a set of numbers is arranging
   all the numbers to be placed in sorted order

2. This problem involves in identifying how lexicographical permutations are
   formed.
   - backtracking algorithm, where each decision involves taking the smallest
     number from the remaining set of numbers;

3. Doing a bruteforce of finding all the permutations in lexicographical order
   and once we find the given input, the next number in the sequence is the
   result.
   - But this will take O(n!) since there are n! permutations

4. Identify the position, that has explored all the sequences from that position
    Example:  _ _ _ _ 4 3 2 1

    Now if you think about it, what is the list of lexicographical permutations
    for { 1, 2, 3 ,4 }:  <- i.e,. explore all paths for index-0 i.e., 1
        - 1 2 3 4
        - 1 2 4 3
        - 1 3 2 4
        - 1 3 4 2
        - 1 4 2 3
        - 1 4 3 2   <- index-0 explored fully

                        _ _ _ _   {1, 2, 3, 4}
                           |
            ---------------------------------
            |       |           |           |
        1 _ _ _     2 _ _ _     3 _ _ _     4 _ _ _
            |
            -------------------------
                                    |
                                1 _ _ _   {2, 3, 4}
                                   |
              -----------------------------------------
              |                    |                  |
              1 2 _ _              1 3 _ _            1 4 _ _
                  |                    |                  |
           ------------         -------------         ------------
           |          |         |           |         |          |
        1 2 3 4    1 2 4 3    1 3 2 4   1 3 4 2     1 4 2 3     1 4 3 2

    - Now when you look at just the set {2, 3, 4} the highest/last number in the
      lexicographical permutations is [4 3 2], i.e., numbers in descending order
      - when we look at the given number from right to left, and all the numbers
        in descending order has explored all the possibilities at that index.
    - More importantly, for the number at index-0, i.e., 1, it has explored
      all the paths for the lexicographical order

5. Except the edge case, only 2 numbers should be swapped

Edge Case:
    - If all numbers are in descending order, then its the last lexicographical
      number
    - Return the first numbre of the possible sequences: i.e., sorted

*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Swap nums[idx] with the number that is greater
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    Solution s;

    // print vector
    auto printVector = [&](const vector<int> &nums) {
        for (auto num : nums)
            cout << num << " ";
        cout << endl;
    };

    // Test Case 1
    {
        vector<int> nums = { 1, 2, 3 };
        s.nextPermutation(nums);
        cout << "RESULT  : ";
        printVector(nums);

        vector<int> answer = { 1, 3, 2 };
        cout << "EXPECTED: ";
        printVector(answer);
        cout << endl;
    }
    // Test Case 2
    {
        vector<int> nums = { 3, 2, 1 };
        s.nextPermutation(nums);
        cout << "RESULT  : ";
        printVector(nums);

        vector<int> answer = { 1, 2, 3 };
        cout << "EXPECTED: ";
        printVector(answer);
        cout << endl;
    }
    // Test Case 3
    {
        vector<int> nums = { 1, 1, 5 };
        s.nextPermutation(nums);
        cout << "RESULT  : ";
        printVector(nums);

        vector<int> answer = { 1, 5, 1 };
        cout << "EXPECTED: ";
        printVector(answer);
        cout << endl;
    }

    return 0;
}

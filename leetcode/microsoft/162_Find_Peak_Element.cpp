#include <iostream>
#include <vector>

using namespace std;

/*
 *     -∞  1 2 3 1 -∞
 *             |
 *
 *     -∞  1 4 2 3 -∞
 *           |   |
 *
 *       1 2 2 3 1 2 3 4 5 6 4
 *             |           |
 *
 *      1 2 3 4 5 6 7 8 9 10 11 12
 *
 *      Observations:
 *          - Check either ends, instead of comparing with -inf at these ends
 *          - Can do regular binary search, comparision will be cheching left &
 *              right of the middle item
 *
 */

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        // Edge case: Only 1 element in the array
        if (n == 1) {
            return 0;
        }

        // Check first and last elements as special cases
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        // Binary search
        int left = 1, right = n - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if mid is a peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            // If left neighbor is larger, search left half
            if (nums[mid - 1] > nums[mid]) {
                right = mid - 1;
            }
            // Else search right half
            else {
                left = mid + 1;
            }
        }

        // This line should never be reached if the input is valid
        return -1;
    }
};

int main()
{
    Solution s;

    // TEST 1
    {
        vector<int> nums { 1, 2, 3, 1 };
        cout << "RESULT  : " << s.findPeakElement(nums) << endl;
        cout << "EXPECTED: " << 2 << "\n" << endl;
    }

    // TEST 2
    {
        vector<int> nums { 1, 2, 1, 3, 5, 6, 4 };
        cout << "RESULT  : " << s.findPeakElement(nums) << endl;
        cout << "EXPECTED: " << 5 << "\n" << endl;
    }
}

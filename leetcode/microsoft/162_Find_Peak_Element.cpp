#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int result = -1;
        return result;
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

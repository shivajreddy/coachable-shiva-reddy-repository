#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums) {}
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
    }

    return 0;
}

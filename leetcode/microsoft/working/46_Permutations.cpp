// 46. Permutations
// https://leetcode.com/problems/permutations

#include <iostream>
#include <vector>

using namespace std;

/*
Observations:
*/

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        return result;
    }
};

int main()
{
    Solution s;

    auto printMatrix = [&](const vector<vector<int>> &matrix) {
        for (auto &v : matrix) {
            for (auto &num : v) {
                cout << num << " ";
            }
            cout << ", ";
        }
        cout << endl;
    };

    // Test Case 1
    {
        vector<int> nums = { 1, 2, 3 };
        auto result = s.permute(nums);
        cout << "RESULT  : ";
        printMatrix(result);

        vector<vector<int>> answer = { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 },
                                       { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } };
        cout << "EXPECTED: ";
        printMatrix(answer);
        cout << endl;
    }
    // Test Case 2
    {
        vector<int> nums = { 0, 1 };
        auto result = s.permute(nums);
        cout << "RESULT  : ";
        printMatrix(result);

        vector<vector<int>> answer = { { 0, 1 }, { 1, 0 } };
        cout << "EXPECTED: ";
        printMatrix(answer);
        cout << endl;
    }
    // Test Case 3
    {
        vector<int> nums = { 1 };
        auto result = s.permute(nums);
        cout << "RESULT  : ";
        printMatrix(result);

        vector<vector<int>> answer = { { 1 } };
        cout << "EXPECTED: ";
        printMatrix(answer);
        cout << endl;
    }

    return 0;
}

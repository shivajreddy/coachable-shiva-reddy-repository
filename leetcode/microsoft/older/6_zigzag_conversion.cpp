// 6. Ziigzag Conversion
// https://leetcode.com/problems/zigzag-conversion

#include <iostream>
#include <string>

using namespace std;

/*
    01234567890123
    PAYPALISHIRING

    06 157  24  3
    PINALSIGYAHRPI

    P           I           N
    A       L   S       I   G
    Y   A       H   R
    P           I

    - direction changes for every R chars


    - O(N): for i'th index, what is the r,c in matrix
    - O(N): for (r,c) position what is the i'th index in result

    -> limits rows, no limit on columns
    rows = 3
    prev_cell = (0, 0), dir = down
    next_cell = (0 + 1, 0) valid

    prev_cell = (1, 0), dir = down
    next_cell = (1 + 1, 0) valid

    prev_cell = (2, 0), dir = down
    next_cell = (2 + 1, 0) INVALID
    next_cell = (2 - 1, 0 + 1) dir = diag VALID

    prev_cell = (1, 1) dir = diag
    next_cel = (1 - 1, 1 + 2)  VALID

    prev_cell = (0, 3) dir = diag
    next_cel = (1 - 1, 1 + 2)  VALID

    (r,c) = (0, 0)
            (1, 0)


    For a given (r,c) to know its index in result
        - How many have already been filled at this position
        rows *


*/

class Solution
{
private:
    pair<int, int> find_position_in_matrix(int i) {}
    int find_new_index(pair<int, int> rc) {}

public:
    string convert(string s, int numRows)
    {
        int n = s.size();

        // Edge case
        if (n == 1) {
            return s;
        }

        string result(n, 'x');

        for (int i = 0; i < n; i++) {
            auto rc = find_position_in_matrix(i);
            auto new_idx = find_new_index(rc);
            result[new_idx] = s[i];
        }

        return result;
    }
};

int main()
{
    Solution s;
    // Test 1
    {
        cout << s.convert("PAYPALISHIRING", 3) << endl;
        cout << "PAHNAPLSIIGYIR\n" << endl;
    }
    // Test 2
    {
        cout << s.convert("PAYPALISHIRING", 4) << endl;
        cout << "PINALSIGYAHRPI\n" << endl;
    }
};

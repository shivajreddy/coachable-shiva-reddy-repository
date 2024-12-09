#include <iostream>
#include <vector>

using namespace std;

/*
Observations:
*/

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        int x = 10;
        return -1;
    }
};

int main()
{
    Solution s;

    // Test  1
    {
        vector<vector<int>> intervals { { 0, 30 }, { 5, 10 }, { 15, 20 } };
        cout << "RESULT  : " << s.minMeetingRooms(intervals) << endl;
        cout << "EXPECTED: " << "2\n" << endl;
    }

    // Test  2
    {
        vector<vector<int>> intervals { { 7, 10 }, { 2, 4 } };
        cout << "RESULT  : " << s.minMeetingRooms(intervals) << endl;
        cout << "EXPECTED: " << "1\n" << endl;
    }

    return 0;
}

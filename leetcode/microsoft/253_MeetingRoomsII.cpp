#include <iostream>
#include <vector>

using namespace std;

/*
Observations:
    - Sort the intervals, sorted for both start & end for the interval
    - Create a MaxHeap (represents the on going meetings), where the meeting
        that ends earliest is on top, so that it can be popped
    - Before adding a new meeting to the MaxHeap, check if the earliest ending
        meeting has already ended (do this until end time of the mettings in the
        meeting room) are smaller than the 'start' time of current interval
    - After adding an interval to the heap, update result as the max size of
        heap discovered

TODO:
- How to create a min heap, with custom comparator (strictly 1st item in tuple,
  or both items)
- Sorting tuples -> and is time n.log(n)
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

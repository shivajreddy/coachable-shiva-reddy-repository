#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
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
*/

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        // Sort the intervals based on start time
        sort(intervals.begin(), intervals.end());

        // printMatrix(intervals);

        int maxRooms = 0;

        // Create a Max-Heap for all intervals
        priority_queue<int, vector<int>, greater<int>> rooms;

        // make_heap(rooms.begin(), rooms.end());
        for (auto &interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            while (!rooms.empty() && rooms.top() <= start) {
                rooms.pop();
            }

            // Add the current interval to rooms
            rooms.push(end);

            if (rooms.size() > maxRooms) {
                maxRooms = rooms.size();
            }
        }
        return maxRooms;
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

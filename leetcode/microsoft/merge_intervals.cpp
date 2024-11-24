// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

#include <algorithm>
#include <vector>

using std::max;
using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Null check
        if (intervals.empty())
            return {};

        // Sort the input array based on start times
        // Time : O(n log.n)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        // Merge while current falls b/w previous range
        for (size_t i = 1; i < intervals.size(); ++i) {
            int prev_end = result.back()[1];
            int start { intervals[i][0] }, end { intervals[i][1] };

            if (prev_end >= start) {
                result.back()[1] = max(prev_end, end);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

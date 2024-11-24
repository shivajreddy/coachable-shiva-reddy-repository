# 56. Merge Intervals
# https://leetcode.com/problems/merge-intervals/

from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Sort the input array based on start times
        # Time : O(n log.n)
        intervals.sort(key=lambda interval: interval[0])

        res = [intervals[0]]

        for i in range(1, len(intervals)):
            prev_end = res[-1][1]
            curr_start, curr_end = intervals[i]

            if prev_end >= curr_start:
                res[-1][1] = max(prev_end, curr_end)
            else:
                res.append(intervals[i])

        return res

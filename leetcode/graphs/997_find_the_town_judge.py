# 997. Find the Town Judge
# https://leetcode.com/problems/find-the-town-judge/description/

from typing import List
from collections import defaultdict

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # Edge case: if n=1 and trust is empty, the only person is the judge
        if not trust:
            return 1 if n == 1 else -1

        # { id: [out-trust, in-trust] }
        hm = defaultdict(lambda: [0, 0])

        # Process all trust relationships
        for a, b in trust:
            hm[a][0] += 1
            hm[b][1] += 1

        # Find the judge: trusted by n-1 people and trusts nobody
        for i in range(1, n + 1):
            if hm[i][0] == 0 and hm[i][1] == n - 1:
                return i

        # No judge found
        return -1

class Solution2:
    def findJudge(self, n: int, trust: list[list[int]]) -> int:
        # Edge case: if n=1 and trust is empty, the only person is the judge
        if n == 1 and not trust:
            return 1
            
        # Create arrays to track trust relationships
        # trusted_count[i] = number of people who trust person i

        # trusts_others[i] = number of people that person i trusts
        trusted_count = [0] * (n + 1)  # +1 because people are labeled 1 to n
        trusts_others = [0] * (n + 1)
        
        # Process all trust relationships
        for a, b in trust:
            trusts_others[a] += 1  # a trusts someone
            trusted_count[b] += 1  # b is trusted by someone
        
        # Find the judge: trusted by n-1 people and trusts nobody
        for i in range(1, n + 1):
            if trusted_count[i] == n - 1 and trusts_others[i] == 0:
                return i
        
        # No judge found
        return -1

s = Solution2()
print(s.findJudge(2, [[1, 2]])) # 2
print(s.findJudge(3, [[1,3],[2, 3]])) # 3
print(s.findJudge(3, [[1,3],[2,3],[3,1]]))  # -1
print(s.findJudge(11, [[1,8],[1,3],[2,8],[2,3],[4,8],[4,3],[5,8],[5,3],[6,8],[6,3],[7,8],[7,3],[9,8],[9,3],[11,8],[11,3]])) # -1

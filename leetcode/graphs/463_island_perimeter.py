# 463. Island Perimeter
# https://leetcode.com/problems/island-perimeter

from typing import List

"""
Run Time: O(n)
 - becase we always only check 4 cells at each cell
 - total run time is O(4.n) => O(n)
 Space : O(1)
"""
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        if not grid: return 0

        rows, cols = len(grid), len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        res = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    res += 4
                    for (dr, dc) in dirs:
                        nr, nc = r + dr, c + dc
                        if nr >= 0 and nr < rows and nc >= 0 and nc < cols and grid[nr][nc] == 1:
                            res -= 1
        return res

s = Solution()
print(s.islandPerimeter([[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]))
print(s.islandPerimeter([[1]]))


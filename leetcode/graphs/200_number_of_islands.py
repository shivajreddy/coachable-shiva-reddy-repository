# 200. Number of Islands
# https://leetcode.com/problems/number-of-islands/

from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        rows, cols = len(grid), len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def explore_island(r: int, c: int) -> None:
            grid[r][c] = '0' # mark tile as visited
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                # Check for land in all 4 directions
                if nr >= 0 and nr < rows and nc >= 0 and nc < cols and grid[nr][nc] == '1':
                    explore_island(nr, nc)

        islands_count = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    explore_island(r, c)
                    islands_count += 1

        # print(islands_count)
        return islands_count 




s = Solution()
print(s.numIslands([
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"], 
    ["0","0","0","0","0"]
]))  # 1

print(s.numIslands([
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
]))  # 3


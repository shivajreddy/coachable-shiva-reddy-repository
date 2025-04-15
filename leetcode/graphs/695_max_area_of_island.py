# 695. Max Area of Island
# https://leetcode.com/problems/max-area-of-island

from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        rows, cols = len(grid), len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def get_island_area(r: int, c: int) -> int:
            grid[r][c] = 0 # mark tile as visited
            area = 1
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                # Check for land in all 4 directions
                if nr >= 0 and nr < rows and nc >= 0 and nc < cols and grid[nr][nc] == 1:
                    area += get_island_area(nr, nc)
            return area

        max_area = 0

        for r in range(rows):
            for c in range(cols):
                # print(f"start here: {r}{c}")
                if grid[r][c] == 1:
                    max_area = max(max_area, get_island_area(r, c))

        # print(max_area)
        return max_area 



        return -1

s = Solution() 
print(s.maxAreaOfIsland([
    [0,0,1,0,0,0,0,1,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,1,1,0,1,0,0,0,0,0,0,0,0],
    [0,1,0,0,1,1,0,0,1,0,1,0,0],
    [0,1,0,0,1,1,0,0,1,1,1,0,0],
    [0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,1,1,0,0,0,0]
])) # 6

print(s.maxAreaOfIsland([[0,0,0,0,0,0,0,0]]))   # 0

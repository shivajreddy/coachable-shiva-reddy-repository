# Rotting Oranges
# https://leetcode.com/problems/rotting-oranges


from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        rotten_cells = deque([])
        rows, cols = len(grid), len(grid[0])
        total_fresh = 0

        # Add all rotten positions to queue. O(n)
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    rotten_cells.append((r, c))
                if grid[r][c] == 1:
                    total_fresh += 1

        # no fresh oranges to rot
        if total_fresh == 0: return 0

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        time_taken = 0

        # BFS
        while rotten_cells:
            size = len(rotten_cells)
            fresh_rotten = False
            for _ in range(size):  # For every i'th minute
                r, c = rotten_cells.popleft()   # current rotten orange cell
                for dr, dc in dirs: # rot oranges in 4 directions
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                        grid[nr][nc] = 2 # Rot the orange at this cell
                        total_fresh -= 1
                        rotten_cells.append((nr, nc))
                        fresh_rotten += 1
            if fresh_rotten:
                time_taken += 1

        return -1 if total_fresh > 0 else time_taken


s = Solution()
print(s.orangesRotting([[2,1,1],[1,1,0],[0,1,1]])) # 4
print(s.orangesRotting([[2,1,1],[0,1,1],[1,0,1]]))  # -1
print(s.orangesRotting([[0,2]]))    # 0


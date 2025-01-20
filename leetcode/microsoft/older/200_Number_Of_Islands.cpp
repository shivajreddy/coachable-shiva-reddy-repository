// 200. Number of Islands
// https : // leetcode.com/problems/number-of-islands/

#include <vector>

using std::vector;

class Solution
{
private:
    // Perform a dfs from a given node
    void dfs(size_t r, size_t c, vector<vector<char>> &grid)
    {
        // Current node is out of bounds
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return;

        // Current node is water
        if (grid[r][c] == '0')
            return;

        // Mark the current node as visited
        grid[r][c] = '0';

        // Explore neighbors
        dfs(r - 1, c, grid); // top
        dfs(r, c + 1, grid); // right
        dfs(r + 1, c, grid); // down
        dfs(r, c - 1, grid); // left
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        size_t rows { grid.size() }, cols { grid[0].size() };

        int totalIslands { 0 };

        for (size_t r = 0; r < rows; ++r) {
            for (size_t c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    totalIslands += 1;
                }
            }
        }

        return totalIslands;
    }
};

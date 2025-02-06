#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Helper function for DFS traversal
        function<int(int, int)> dfs = [&](int r, int c)
        {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            {
                return 0; // Out of bounds or no fish
            }

            int fish = grid[r][c]; // Collect fish at this cell
            grid[r][c] = 0;        // Mark as visited by setting it to 0

            // Explore all 4 directions
            fish += dfs(r + 1, c); // Down
            fish += dfs(r - 1, c); // Up
            fish += dfs(r, c + 1); // Right
            fish += dfs(r, c - 1); // Left

            return fish;
        };

        // Iterate through each cell in the grid
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] > 0)
                { // Start DFS if it's a water cell
                    maxFish = max(maxFish, dfs(r, c));
                }
            }
        }

        return maxFish;
    }
};

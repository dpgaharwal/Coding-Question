#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countServers(const vector<vector<int>> &grid)
    {
        vector<int> col(size(grid[0]), 0), row(size(grid), 0);
        int r = 0;
        for (int i = 0; i < size(grid); ++i)
        {
            for (int j = 0; j < size(grid[0]); ++j)
                if (grid[i][j])
                {
                    col[j]++;
                    row[i]++;
                }
            if (row[i] > 1)
                r += row[i];
        }

        for (int j = 0; j < size(grid[0]); ++j)
            if (col[j] > 1)
            {
                for (int i = 0; i < size(grid); ++i)
                {
                    if (row[i] > 1 && grid[i][j])
                        col[j]--;
                }
                r += col[j];
            }

        return r;
    }
};
// Problem Link: https://leetcode.com/problems/grid-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {

        int n = grid[0].size();
        long long firstRow = 0;
        long long secondRow = 0;

        for (int i = 1; i < n; i++)
        {
            firstRow += grid[0][i];
        }

        long long ans = firstRow;
        for (int i = 0; i < n - 1; i++)
        {
            firstRow -= grid[0][i + 1];
            secondRow += grid[1][i];
            ans = min(ans, max(firstRow, secondRow));
        }
        return ans;
    }
};
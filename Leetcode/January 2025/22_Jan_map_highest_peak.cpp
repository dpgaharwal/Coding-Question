// Problem Link: https://leetcode.com/problems/map-of-highest-peak/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    isWater[i][j] = 0;
                }
                else
                    isWater[i][j] = -1;
            }
        }
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while (!q.empty())
        {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int x = currx + dx[j];
                int y = curry + dy[j];
                if (x >= 0 && x < n && y >= 0 && y < m && isWater[x][y] == -1)
                {
                    isWater[x][y] = isWater[currx][curry] + 1;
                    q.push({x, y});
                }
            }
        }
        return isWater;
    }
};
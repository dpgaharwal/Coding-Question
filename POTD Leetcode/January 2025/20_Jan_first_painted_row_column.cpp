// Problem Link: https://leetcode.com/problems/first-completely-painted-row-or-column/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> pos;
        vector<int> rowPainted(m, 0),
            colPainted(n, 0); // Start with 0 painted cells

        // Map each matrix value to its (row, col) position
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                pos[mat[i][j]] = {i, j};
            }
        }

        // Process the arr
        for (int i = 0; i < arr.size(); ++i)
        {
            auto [row, col] = pos[arr[i]];
            rowPainted[row]++;
            colPainted[col]++;

            // Check if the row or column is fully painted
            if (rowPainted[row] == n || colPainted[col] == m)
            {
                return i;
            }
        }
        return -1; // Shouldn't happen
    }
};
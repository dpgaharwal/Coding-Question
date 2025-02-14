#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent, size;

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        parent.resize(n * n);
        size.resize(n * n, 1);
        for (int i = 0; i < n * n; ++i)
        {
            parent[i] = i;
        }

        // Directions for up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // First pass: Union adjacent 1s
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    for (auto &dir : dirs)
                    {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            unite(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }

        // Second pass: Find the maximum island size after changing one 0 to 1
        int maxSize = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    set<int> uniqueRoots;
                    for (auto &dir : dirs)
                    {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            uniqueRoots.insert(find(x * n + y));
                        }
                    }
                    int currentSize = 1; // Changing the current 0 to 1
                    for (int root : uniqueRoots)
                    {
                        currentSize += size[root];
                    }
                    maxSize = max(maxSize, currentSize);
                }
            }
        }

        // If the grid is all 1s, return the size of the entire grid
        if (maxSize == 0)
        {
            return n * n;
        }

        return maxSize;
    }
};
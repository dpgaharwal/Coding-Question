#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        DSU dsu(n);

        // Pair each number with its index and sort by values
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < n; i++)
        {
            numWithIndex.push_back({nums[i], i});
        }
        sort(numWithIndex.begin(), numWithIndex.end());

        // Group indices based on the limit condition
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(numWithIndex[i].first - numWithIndex[i + 1].first) <=
                limit)
            {
                dsu.unite(numWithIndex[i].second, numWithIndex[i + 1].second);
            }
        }

        // Create groups
        vector<vector<int>> groups(n);
        for (int i = 0; i < n; i++)
        {
            groups[dsu.find(i)].push_back(i);
        }

        // Sort values within each group
        vector<int> result(nums);
        for (auto &group : groups)
        {
            if (!group.empty())
            {
                vector<int> values;
                for (int index : group)
                {
                    values.push_back(nums[index]);
                }
                sort(values.begin(), values.end());
                sort(group.begin(), group.end());

                // Replace original indices with sorted values
                for (int i = 0; i < group.size(); i++)
                {
                    result[group[i]] = values[i];
                }
            }
        }

        return result;
    }
};
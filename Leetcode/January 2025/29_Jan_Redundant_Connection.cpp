#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return false; // Already connected, forms a cycle
        }
        parent[rootX] = rootY;
        return true;
    }

private:
    vector<int> parent;
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UnionFind uf(n);
        for (const auto &edge : edges)
        {
            if (!uf.unionSets(edge[0], edge[1]))
            {
                return edge; // This edge forms a cycle
            }
        }
        return {}; // No redundant edge found
    }
};
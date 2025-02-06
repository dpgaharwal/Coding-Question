#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);

        // Step 1: Build the reverse graph and
        // calculate in-degree for each node
        for (int i = 0; i < n; ++i)
        {
            for (int neighbor : graph[i])
            {
                reverseGraph[neighbor].push_back(i);
                inDegree[i]++;
            }
        }

        // Step 2: Initialize the queue
        // with terminal nodes (in-degree == 0)
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Step 3: Perform BFS to
        // propagate safety to other nodes
        vector<int> safeNodes;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseGraph[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Sort the result
        // in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
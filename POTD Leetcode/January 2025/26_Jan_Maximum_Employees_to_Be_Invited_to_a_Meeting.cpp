#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int start)
    {
        queue<pair<int, int>> q; //{node,pathLength}
        q.push({start, 0});
        int maxDistance = 0;

        while (!q.empty())
        {
            auto [currNode, dist] = q.front();
            q.pop();
            // explore path
            for (auto &v : adj[currNode])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, dist + 1});
                    maxDistance = max(maxDistance, dist + 1);
                }
            }
        }
        return maxDistance;
    }
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();
        // it is important to take vector in adj map because a node can be favorite
        // of multiple node so when we reverse it leads to multiple paths in bfs later
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            int u = i;
            int v = favorite[u];
            adj[v].push_back(u); // reverse the directions, so that we find chain length easily
        }
        // we have 2 types of cycles fully contained cycles and semi cycles
        int semiCycleMax = 0;
        int fullCycleMax = 0;

        // why we take a loop? for example we find multiple cycles
        //  1->2->3->1 and 4->5->6->7->4 without loop we only find first cycle
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                // store node count for finding cycle length
                unordered_map<int, int> mp;
                int currNode = i;
                int nodeCount = 0;
                while (!visited[currNode])
                { // we run loop until cycle is not detected
                    visited[currNode] = true;
                    mp[currNode] = nodeCount;
                    nodeCount++;
                    int nextNode = favorite[currNode];
                    // nextNode already visited we found a cycle
                    if (mp.count(nextNode))
                    {
                        int cycleLength = nodeCount - mp[nextNode];
                        fullCycleMax = max(fullCycleMax, cycleLength);
                        // if cycle length is 2, it will be a semi cycle
                        if (cycleLength == 2)
                        {
                            // find longest chain
                            vector<bool> visitedNodes(n, false);
                            // there will be chances to find multiple semi cycles and
                            // it is valid to sum all the semi cycles
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            semiCycleMax += 2 + bfs(adj, visitedNodes, currNode) + bfs(adj, visitedNodes, nextNode);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(fullCycleMax, semiCycleMax);
    }
};
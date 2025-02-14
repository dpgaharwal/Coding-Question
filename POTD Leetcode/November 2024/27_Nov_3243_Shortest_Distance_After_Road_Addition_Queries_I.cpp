class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i)
        {
            graph[i].push_back(i + 1);
        }

        vector<int> answer;
        for (const auto &query : queries)
        {
            int ui = query[0];
            int vi = query[1];
            graph[ui].push_back(vi);

            // Perform BFS to find shortest path from 0 to n - 1
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(0);
            dist[0] = 0;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr])
                {
                    if (dist[neighbor] == -1)
                    {
                        dist[neighbor] = dist[curr] + 1;
                        q.push(neighbor);
                    }
                }
            }

            answer.push_back(dist[n - 1]);
        }
        return answer;
    }
};
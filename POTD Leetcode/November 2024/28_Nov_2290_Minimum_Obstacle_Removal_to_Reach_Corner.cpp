class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int sz = m * n;
        vector<int> dist(sz, INT_MAX);
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0] = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!dq.empty())
        {
            auto [r, c] = dq.front();
            dq.pop_front();
            int idx = r * n + c;
            if (r == m - 1 && c == n - 1)
            {
                return dist[idx];
            }
            for (int d = 0; d < 4; ++d)
            {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int nidx = nr * n + nc;
                    int cost = grid[nr][nc];
                    if (dist[nidx] > dist[idx] + cost)
                    {
                        dist[nidx] = dist[idx] + cost;
                        if (cost == 0)
                            dq.push_front({nr, nc});
                        else
                            dq.push_back({nr, nc});
                    }
                }
            }
        }
        // Should not reach here
        return -1;
    }
};

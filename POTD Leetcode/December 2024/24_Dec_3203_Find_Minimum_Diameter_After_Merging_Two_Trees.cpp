class Solution
{
private:
private:
    void build(vector<vector<int>> &adj, vector<vector<int>> &edges, int n)
    {
        adj.resize(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }

    int bfs_farthest_node(const vector<vector<int>> &adj, int start, vector<int> &distance)
    {
        queue<int> q;
        q.push(start);
        distance[start] = 0;
        int farthest = start;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (distance[v] == -1)
                {
                    distance[v] = distance[u] + 1;
                    q.push(v);
                    if (distance[v] > distance[farthest])
                    {
                        farthest = v;
                    }
                }
            }
        }
        return farthest;
    }

    int get_diameter(const vector<vector<int>> &adj, int &u, int &v)
    {
        vector<int> distance1(adj.size(), -1);
        u = bfs_farthest_node(adj, 0, distance1);
        vector<int> distance2(adj.size(), -1);
        v = bfs_farthest_node(adj, u, distance2);
        return distance2[v];
    }

    int get_center(const vector<vector<int>> &adj, int u, int v)
    {
        vector<int> distance_u(adj.size(), -1);
        bfs_farthest_node(adj, u, distance_u);
        vector<int> distance_v(adj.size(), -1);
        bfs_farthest_node(adj, v, distance_v);
        int n = adj.size();
        int len = distance_u[v];
        int center = u;
        for (int i = 0; i < n; ++i)
        {
            if (distance_u[i] + distance_v[i] == len)
            {
                if (distance_u[i] == len / 2 || distance_u[i] == (len + 1) / 2)
                {
                    center = i;
                    break;
                }
            }
        }
        return center;
    }

    int get_max_distance_from_center(const vector<vector<int>> &adj, int center)
    {
        vector<int> distance(adj.size(), -1);
        queue<int> q;
        q.push(center);
        distance[center] = 0;
        int max_distance = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (distance[v] == -1)
                {
                    distance[v] = distance[u] + 1;
                    q.push(v);
                    if (distance[v] > max_distance)
                    {
                        max_distance = distance[v];
                    }
                }
            }
        }
        return max_distance;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1, adj2;
        build(adj1, edges1, n);
        build(adj2, edges2, m);

        int u1, v1;
        int D1 = get_diameter(adj1, u1, v1);
        int center1 = get_center(adj1, u1, v1);
        int H1 = get_max_distance_from_center(adj1, center1);

        int u2, v2;
        int D2 = get_diameter(adj2, u2, v2);
        int center2 = get_center(adj2, u2, v2);
        int H2 = get_max_distance_from_center(adj2, center2);

        int minimal_diameter = max({D1, D2, H1 + 1 + H2});
        return minimal_diameter;
    }
};
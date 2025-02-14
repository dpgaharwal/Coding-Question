#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int s, int en, vector<vector<int>> &adj, int n)
    {
        vector<bool> vis(n);
        stack<int> st;
        st.push(s);
        vis[s] = true;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (top == en)
            {
                return true;
            }
            for (auto &node : adj[top])
            {
                if (!vis[node])
                {
                    st.push(node);
                    vis[node] = true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &pre,
                                     vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for (int i = 0; i < pre.size(); i++)
        {
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
            deg[v]++;
        }
        vector<bool> ans;
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            bool res = dfs(start, end, adj, n);
            ans.push_back(res);
        }
        return ans;
    }
};
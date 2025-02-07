class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> mp, count_mp;
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            if (mp.find(queries[i][0]) != mp.end())
            {
                count_mp[mp[queries[i][0]]] -= 1;
                if (count_mp[mp[queries[i][0]]] == 0)
                    count_mp.erase(mp[queries[i][0]]);
            }
            mp[queries[i][0]] = queries[i][1];
            count_mp[queries[i][1]] += 1;
            ans.push_back(count_mp.size());
        }
        return ans;
    }
};
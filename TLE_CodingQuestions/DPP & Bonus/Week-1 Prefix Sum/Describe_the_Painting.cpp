// Problem Link: https://leetcode.com/problems/describe-the-painting/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        map<int, long long> colorChanges;
        for (const auto &segment : segments)
        {
            int start = segment[0];
            int end = segment[1];
            int color = segment[2];
            colorChanges[start] += color;
            colorChanges[end] -= color;
        }

        vector<vector<long long>> result;
        long long currentColor = 0;
        int previousPoint = -1;

        for (auto it : colorChanges)
        {
            if (previousPoint != -1 && currentColor > 0)
            {
                result.push_back({previousPoint, it.first, currentColor});
            }
            currentColor += it.second;
            previousPoint = it.first;
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> segments = {{1, 4, 5}, {4, 7, 7}, {1, 7, 9}};
    vector<vector<long long>> ans = s.splitPainting(segments);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
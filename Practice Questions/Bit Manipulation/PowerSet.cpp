// Problem Link: https://leetcode.com/problems/subsets/

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
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // using bit manipulation
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    for (const auto &subset : result)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
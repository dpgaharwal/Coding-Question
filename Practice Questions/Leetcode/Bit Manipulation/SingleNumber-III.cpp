// Problem Link: https://leetcode.com/problems/single-number-iii/

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
    vector<int> singleNumber(vector<int> &nums)
    {
        // Approach : Using bucket
        long xorr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorr ^= nums[i];
        }

        int rightmost = (xorr & (xorr - 1)) ^ xorr;
        int b1 = 0, b2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & rightmost)
                b1 ^= nums[i];
            else
                b2 ^= nums[i];
        }
        return {b1, b2};
    }
};
// class Solution
// {
// public:
//     vector<int> singleNumber(vector<int> &nums)
//     {
//         // Approach:Using map
//         unordered_map<int, int> mp;
//         for (int i : nums)
//         {
//             mp[i]++;
//         }
//         vector<int> ans;
//         for (auto i : mp)
//         {
//             if (i.second == 1)
//             {
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//         }
// };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = sol.singleNumber(nums);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
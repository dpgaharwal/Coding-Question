// Problem Link: https://leetcode.com/problems/single-number/

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
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int num : nums)
        {
            result ^= num;
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 3, 4, 4, 13, 13};
    cout << sol.singleNumber(nums) << endl;

    return 0;
}
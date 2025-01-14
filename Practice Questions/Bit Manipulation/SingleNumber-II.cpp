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
    // Approach 3 :Use of buckets
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ones = 0, twos = 0;
        for (int i = 0; i < n; i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};
/*
class Solution
{
public:
    // Approach 2
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i += 3)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[n - 1];
    }
};
*/

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         int ans = 0;
//         for (int bitIndex = 0; bitIndex < 32; bitIndex++)
//         {
//             int cnt = 0;
//             for (int i = 0; i < n; i++)
//             {
//                 if (nums[i] & (1 << bitIndex))
//                     cnt++;
//             }
//             if (cnt % 3 == 1)
//                 ans = ans | (1 << bitIndex);
//         }

//         return ans;
//     }
// };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}
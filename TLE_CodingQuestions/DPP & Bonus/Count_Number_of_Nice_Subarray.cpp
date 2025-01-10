// Problem Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Approach: Prefix Sum

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
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
                nums[i] = 0;
            else
                nums[i] = 1;
        }
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}

/***********************************************

// Another Approach: Sliding Window

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lessequaltok(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        int sum = 0;

        while (r < n)
        {
            sum += (nums[r] % 2);

            while (sum > goal)
            {
                sum -= (nums[l] % 2);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return lessequaltok(nums, k) - lessequaltok(nums, k - 1);
    }
};
*/
// Problem Link: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + nums[i - 1];
        }
        int totalWays = 0;
        int MOD = int(1e9 + 7);
        int i = 0;
        int minMid = 0;
        int maxMid = 0;
        while (i < n - 2)
        {
            // for min possible end of mid, get 1st: sum[0...minMid] >= 2*sum[0...i]
            minMid = max(minMid, i + 1);
            while (minMid < n - 1 and (pref[minMid + 1] < 2 * pref[i + 1]))
            {
                minMid++;
            }

            // for max possible end of mid, get last: sum[i+1...maxMid] <= sum[maxMid+1...n-1]
            maxMid = max(maxMid, minMid);
            while (maxMid < n - 1 and (pref[maxMid + 1] - pref[i + 1]) <= (pref[n] - pref[maxMid + 1]))
            {
                maxMid++;
            }

            int currWays = max(0, maxMid - minMid); // we are already 1+ the possible maxMid
            totalWays += currWays;
            totalWays %= MOD;
            i++;
        }
        return totalWays;
    }
};
/*https://leetcode.com/problems/left-and-right-sum-differences*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();

        // Prefix sum array
        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }

        // Suffix sum array
        vector<int> suff(n, 0);
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + nums[i];
        }

        // Result array
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = abs(pref[i] - suff[i]);
        }

        return result;
    }
};

// URL: https://leetcode.com/problems/subarray-sum-equals-k/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        int curr = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i : nums)
        {
            curr += i;
            res += mp[curr - k];
            mp[curr]++;
        }
        return res;
    }
};
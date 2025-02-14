/*https://leetcode.com/problems/running-sum-of-1d-array/*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefixSum[i] += prefixSum[i - 1] + nums[i];
        }
        return prefixSum;
    }
};
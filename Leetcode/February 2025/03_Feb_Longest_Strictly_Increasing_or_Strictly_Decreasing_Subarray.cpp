#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int maxLen = 1;
        int incLen = 1, decLen = 1;

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                incLen++;
            }
            else
            {
                incLen = 1;
            }

            if (nums[i] < nums[i - 1])
            {
                decLen++;
            }
            else
            {
                decLen = 1;
            }

            maxLen = max(maxLen, max(incLen, decLen));
        }

        return maxLen;
    }
};
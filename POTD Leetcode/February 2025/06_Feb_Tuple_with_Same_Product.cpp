#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int N = nums.size();
        unordered_map<long, int> track;

        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                track[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for (auto &x : track)
        {
            int cnt = x.second;
            ans += 8 * (cnt * (cnt - 1) / 2);
        }

        return ans;
    }
};
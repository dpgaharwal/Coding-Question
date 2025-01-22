// Problem Link: https://leetcode.com/problems/regular-expression-matching/

// Approach: Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Initialize dp for patterns like a*, a*b*, a*b*c* (empty string case)
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the dp table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // Case 1: Treat '*' as zero occurrence of the preceding element
                    dp[i][j] = dp[i][j - 2];
                    // Case 2: Treat '*' as one or more occurrence if preceding matches
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        // Final result
        return dp[m][n];
    }
};

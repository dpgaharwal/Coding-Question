class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        unordered_set<int> travel(days.begin(), days.end());
        vector<int> dp(366, 0); // DP array for all days in the year.

        for (int i = 1; i <= 365; i++)
        {
            if (!travel.count(i))
            { // If not a travel day, cost stays the same.
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = min({
                    dp[i - 1] + costs[0],         // 1-day pass
                    dp[max(0, i - 7)] + costs[1], // 7-day pass
                    dp[max(0, i - 30)] + costs[2] // 30-day pass
                });
            }
        }
        return dp[365];
    }
};
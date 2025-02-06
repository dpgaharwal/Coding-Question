class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        const int MOD = 1000000007;
        int L = words[0].length();
        int m = target.length();

        // Precompute count[k][c]: number of words that have character c at position k
        vector<vector<int>> count(L, vector<int>(26, 0));
        for (int k = 0; k < L; ++k)
        {
            for (const string &word : words)
            {
                count[k][word[k] - 'a']++;
            }
        }

        // Initialize DP array
        vector<int> dp(m + 1, 0);
        dp[0] = 1; // Empty target can be formed in one way

        // Iterate through each position in the words
        for (int k = 0; k < L; ++k)
        {
            // Update DP in reverse to prevent overwriting values needed for current update
            for (int i = m; i >= 1; --i)
            {
                char c = target[i - 1];
                dp[i] = (dp[i] + dp[i - 1] * count[k][c - 'a']) % MOD;
            }
        }

        return dp[m];
    }
};
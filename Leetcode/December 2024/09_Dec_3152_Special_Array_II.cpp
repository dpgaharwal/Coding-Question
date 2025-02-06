class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        // Step 1: Preprocess the parity differences
        vector<int> parity(n - 1, 0);
        for (int i = 0; i < n - 1; ++i)
        {
            if ((nums[i] % 2) != (nums[i + 1] % 2))
            {
                parity[i] = 1;
            }
        }

        // Step 2: Create a prefix sum array for the parity information
        vector<int> prefix_sum(n, 0);
        for (int i = 1; i < n; ++i)
        {
            prefix_sum[i] = prefix_sum[i - 1] + parity[i - 1];
        }

        // Step 3: Answer the queries
        vector<bool> result;
        for (const auto &query : queries)
        {
            int fromi = query[0];
            int toi = query[1];

            if (fromi == toi)
            {
                result.push_back(true);
            }
            else
            {
                int count = prefix_sum[toi] - prefix_sum[fromi];
                result.push_back(count == toi - fromi);
            }
        }

        return result;
    }
};

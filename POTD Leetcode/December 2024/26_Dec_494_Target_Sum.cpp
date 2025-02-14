class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // Memoization table: map of (index, current_sum) to the count of ways
        unordered_map<string, int> memo;

        // Helper function for recursion with memoization
        function<int(int, int)> dfs = [&](int index, int current_sum) -> int
        {
            // Base case: If we've processed all numbers
            if (index == nums.size())
            {
                return current_sum == target ? 1 : 0;
            }

            // Generate a unique key for the current state
            string key = to_string(index) + "," + to_string(current_sum);

            // Check if this state has already been computed
            if (memo.count(key))
            {
                return memo[key];
            }

            // Explore both adding and subtracting the current number
            int add = dfs(index + 1, current_sum + nums[index]);
            int subtract = dfs(index + 1, current_sum - nums[index]);

            // Store the result in the memoization table
            memo[key] = add + subtract;

            return memo[key];
        };

        // Start the recursion from index 0 and sum 0
        return dfs(0, 0);
    }
};

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        long long sum = 0, maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            freq[nums[right]]++;

            while (freq[nums[right]] > 1 || (right - left + 1) > k)
            {
                sum -= nums[left];
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            if (right - left + 1 == k)
            {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

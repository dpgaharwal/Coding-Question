class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++)
        {
            diff[i] = nums[i] - i;
        }

        unordered_map<int, int> freq;
        for (int d : diff)
        {
            freq[d]++;
        }

        long long total_pairs = (long long)n * (n - 1) / 2;

        long long good_pairs = 0;
        for (auto &[key, count] : freq)
        {
            if (count >= 2)
                good_pairs += (long long)count * (count - 1) / 2;
        }

        long long bad_pairs = total_pairs - good_pairs;
        return bad_pairs;
    }
};
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        // Sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0;
        int max_len = 1;
        for (int r = 0; r < n; r++)
        {
            while (nums[r] - nums[l] > 2 * k)
                l++;
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};
class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            long long operations = 0;
            for (int x : nums)
            {
                operations += (x - 1) / mid;
                if (operations > maxOperations)
                {
                    break;
                }
            }

            if (operations > maxOperations)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};
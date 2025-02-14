class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                int value = matrix[i][j];
                totalSum += abs(value);
                minAbsValue = min(minAbsValue, abs(value));
                if (value < 0)
                {
                    ++negativeCount;
                }
            }
        }

        // If the count of negative numbers is odd, adjust the total sum
        if (negativeCount % 2 == 1)
        {
            totalSum -= 2 * minAbsValue;
        }

        return totalSum;
    }
};

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        if (n < 2)
        {
            return 0; // or as specified
        }
        int max_so_far = values[0] + 0;
        int overall_max = INT_MIN;
        for (int j = 1; j < n; ++j)
        {
            int score = max_so_far + (values[j] - j);
            if (score > overall_max)
            {
                overall_max = score;
            }
            if (values[j] + j > max_so_far)
            {
                max_so_far = values[j] + j;
            }
        }
        return overall_max;
    }
};
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Populate the min-heap with (value, index) pairs
        for (int i = 0; i < n; ++i)
        {
            minHeap.emplace(nums[i], i);
        }

        long long score = 0;

        while (!minHeap.empty())
        {
            auto [value, index] = minHeap.top();
            minHeap.pop();

            if (marked[index])
                continue;

            score += value;

            marked[index] = true;
            if (index > 0)
                marked[index - 1] = true;
            if (index < n - 1)
                marked[index + 1] = true;
        }

        return score;
    }
};
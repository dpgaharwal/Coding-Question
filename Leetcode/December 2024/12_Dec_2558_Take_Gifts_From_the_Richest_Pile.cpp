class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> maxHeap;

        for (int gift : gifts)
        {
            maxHeap.push(gift);
        }

        for (int i = 0; i < k; ++i)
        {
            int maxPile = maxHeap.top();
            maxHeap.pop();

            int remainingGifts = floor(sqrt(maxPile));

            maxHeap.push(remainingGifts);
        }

        long long totalRemaining = 0;
        while (!maxHeap.empty())
        {
            totalRemaining += maxHeap.top();
            maxHeap.pop();
        }

        return totalRemaining;
    }
};
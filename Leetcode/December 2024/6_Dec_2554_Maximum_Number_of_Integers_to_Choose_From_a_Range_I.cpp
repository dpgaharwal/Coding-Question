class Solution
{
public:
    int maxCount(vector<int> &banned, int n, long long maxSum)
    {
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        long long currentSum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (bannedSet.find(i) == bannedSet.end())
            {
                if (currentSum + i <= maxSum)
                {
                    currentSum += i;
                    count++;
                }
                else
                {
                    break;
                }
            }
        }

        return count;
    }
};

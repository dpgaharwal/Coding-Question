class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(),
             [](auto &a, auto &b)
             { return a[1] < b[1]; });

        int n = (int)events.size();
        vector<int> M(n, 0);
        M[0] = events[0][2];
        for (int i = 1; i < n; i++)
        {
            M[i] = max(M[i - 1], events[i][2]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, events[i][2]);
        }

        for (int i = 0; i < n; i++)
        {
            int start = events[i][0];
            int val = events[i][2];

            int left = 0, right = i - 1;
            int best_j = -1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (events[mid][1] < start)
                {
                    best_j = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            int totalVal = val;
            if (best_j != -1)
            {
                totalVal += M[best_j];
            }
            ans = max(ans, totalVal);
        }

        return ans;
    }
};
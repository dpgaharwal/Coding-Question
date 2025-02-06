class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        // Lambda to compute marginal gain if we add 1 student to a class (p, t)
        auto gain = [&](int p, int t)
        {
            // (p+1)/(t+1) - p/t
            return double(p + 1) / (t + 1) - double(p) / t;
        };

        // Max-heap storing {marginal_gain, p, t}
        priority_queue<array<double, 3>> pq;

        // Build initial heap
        for (auto &c : classes)
        {
            int p = c[0], t = c[1];
            double delta = gain(p, t);
            pq.push({delta, double(p), double(t)});
        }

        // Assign extraStudents
        while (extraStudents--)
        {
            auto top = pq.top();
            pq.pop();
            double curGain = top[0], p = top[1], t = top[2];
            // Add 1 student
            p++;
            t++;
            double newGain = gain((int)p, (int)t);
            pq.push({newGain, p, t});
        }

        // Compute final average
        double ans = 0.0;
        int n = classes.size();
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            double p = top[1], t = top[2];
            ans += (p / t);
        }
        return ans / n;
    }
};

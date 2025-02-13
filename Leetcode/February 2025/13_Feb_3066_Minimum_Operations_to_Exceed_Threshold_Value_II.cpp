#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        bool allGreater = true;
        for (int num : nums)
        {
            if (num < k)
            {
                allGreater = false;
                break;
            }
        }
        if (allGreater)
        {
            return 0;
        }

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (int num : nums)
        {
            minHeap.push(static_cast<long long>(num));
        }

        int operations = 0;

        while (minHeap.size() >= 2 && minHeap.top() < k)
        {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            long long newElement = min(x, y) * 2 + max(x, y);
            minHeap.push(newElement);

            operations++;
        }

        while (!minHeap.empty() && minHeap.top() < k)
        {
            operations++;
            minHeap.pop();
        }

        return operations;
    }
};
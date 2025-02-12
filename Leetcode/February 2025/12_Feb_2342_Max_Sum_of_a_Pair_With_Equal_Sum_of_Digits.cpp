#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int sumOfDigits(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> digitSumMap;
        int maxSum = -1;

        for (int num : nums)
        {
            int digitSum = sumOfDigits(num);
            digitSumMap[digitSum].push_back(num);

            if (digitSumMap[digitSum].size() > 2)
            {
                sort(digitSumMap[digitSum].rbegin(),
                     digitSumMap[digitSum].rend());
                digitSumMap[digitSum].pop_back();
            }

            if (digitSumMap[digitSum].size() == 2)
            {
                maxSum = max(maxSum, digitSumMap[digitSum][0] +
                                         digitSumMap[digitSum][1]);
            }
        }

        return maxSum;
    }
};
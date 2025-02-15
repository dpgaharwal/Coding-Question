#include <string>
#include <vector>

class Solution
{
public:
    int punishmentNumber(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            int square = i * i;
            if (canPartition(std::to_string(square), i))
            {
                sum += square;
            }
        }
        return sum;
    }

private:
    bool canPartition(const std::string &s, int target, int index = 0, int currentSum = 0)
    {
        if (index == s.length())
        {
            return currentSum == target;
        }
        int num = 0;
        for (int i = index; i < s.length(); ++i)
        {
            num = num * 10 + (s[i] - '0');
            if (canPartition(s, target, i + 1, currentSum + num))
            {
                return true;
            }
        }
        return false;
    }
};
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

class Solution
{
public:
    int isSumString(string S)
    {
        int length = S.length();
        for (int len1 = 1; len1 < length; len1++)
        {
            for (int len2 = 1; len2 < length - len1; len2++)
            {
                if (isValidSplit(S, 0, len1, len2))
                    return 1;
            }
        }
        return 0;
    }

    bool isValidSplit(string &str, int start, int len1, int len2)
    {
        // Extract the first and second numbers
        string num1 = str.substr(start, len1);
        string num2 = str.substr(start + len1, len2);
        string sumResult = addStrings(num1, num2);

        int remainingLength = str.length() - start - len1 - len2;

        if (sumResult.length() > remainingLength)
            return false;

        if (sumResult == str.substr(start + len1 + len2, sumResult.length()))
        {
            if (sumResult.length() == remainingLength)
                return true;
            return isValidSplit(str, start + len1, len2, sumResult.length());
        }
        return false;
    }

    string addStrings(string num1, string num2)
    {
        string result;
        int carry = 0;
        int i = num1.length() - 1, j = num2.length() - 1;

        // Add digits from the end
        while (i >= 0 || j >= 0 || carry)
        {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        // Reverse to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        string inputString;
        cin >> inputString;
        Solution solution;
        cout << solution.isSumString(inputString) << endl;
        cout << "~" << "\n";
    }
    return 0;
}
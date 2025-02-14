// Problem Link: https://leetcode.com/problems/divide-two-integers/

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
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == divisor)
            return 1;
        if (dividend == 0)
            return 0;
        bool sign = true;
        long long ans = 0;
        if (dividend <= 0 && divisor > 0)
            sign = false;
        if (dividend > 0 && divisor < 0)
            sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        while (n >= d)
        {
            long long count = 0;
            while (n >= (d << (count + 1)))
            {
                count++;
            }
            n -= d << count;
            ans += (1LL << count);
        }
        cout << ans << endl;
        ans = sign ? ans : -ans;
        cout << ans;
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return (int)ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution sol;
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;
    int result = sol.divide(dividend, divisor);
    cout << "Result: " << result << endl;
    return 0;
}
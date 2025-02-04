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
    void helper(int open, int close, int n, string current, vector<string> &result)
    {
        if (current.length() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        // open bracket
        if (open < n)
            helper(open + 1, close, n, current + '(', result);
        if (close < open)
            helper(open, close + 1, n, current + ')', result);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        helper(0, 0, n, "", result);
        return result;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<string> result = sol.generateParenthesis(n);
    for (string str : result)
        cout << str;

    return 0;
}
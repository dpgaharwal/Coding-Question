// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Q
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

int solve(int n)
{
    // Base Case
    if (n == 1)
        return 1;

    // Small Calculation
    if (n & 1)
        return 1 + solve(3 * n + 1);
    else
        return 1 + solve(n / 2);
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
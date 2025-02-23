// Problem Link: https://codeforces.com/problemset/problem/1514/B

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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll result = 1;
    for (ll i = 0; i < k; ++i)
    {
        result = (result * n) % MOD;
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
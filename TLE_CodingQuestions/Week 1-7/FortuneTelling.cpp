// Problem Link: https://codeforces.com/problemset/problem/1634/

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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll f = 1;
    // f==0--> f is odd
    for (int i = 0; i < n; i++)
    {
        if (v[i] & 1)
        {
            f = (!f);
        }
    }
    // if we start with odd number we end at the number same as parity of f
    if (x & 1)
    {
        if (!((f ^ y) & 1LL))
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    else
    {
        if (!((f ^ y) & 1LL))
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }
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
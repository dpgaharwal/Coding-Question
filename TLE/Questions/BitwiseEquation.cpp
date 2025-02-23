// Problem Link: https://www.codechef.com/problems/BITEQU

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
    ll n;
    cin >> n;
    ll a = (1LL << 36) + (1LL << 37);
    ll b = (1LL << 36);
    ll c = (1LL << 35);
    ll d = (1LL << 36) + (1LL << 35) + n;
    cout << a << " " << b << " " << c << " " << d << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

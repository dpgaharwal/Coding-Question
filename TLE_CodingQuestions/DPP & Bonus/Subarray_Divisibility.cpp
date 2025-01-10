// Problem Link: https://cses.fi/problemset/task/1662/
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        sum = (sum % n + n) % n;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans << endl;

    return 0;
}
// Problem: Kuriyama Mirai's Stones (http://codeforces.com/problemset/problem/433/B)
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

    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; ++i)
        cin >> vec[i];

    vector<ll> presum(n, 0), sorted(n, 0);
    presum[0] = vec[0];

    for (ll i = 1; i < n; i++)
        presum[i] = presum[i - 1] + vec[i];

    sort(vec.begin(), vec.end());
    sorted[0] = vec[0];

    for (ll i = 1; i < n; i++)
        sorted[i] = sorted[i - 1] + vec[i];

    ll m;
    cin >> m;

    for (ll i = 0; i < m; ++i)
    {
        ll t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1)
        {
            ll ans = presum[r] - ((l > 0) ? presum[l - 1] : 0);
            cout << ans << endl;
        }
        else
        {
            ll ans = sorted[r] - ((l > 0) ? sorted[l - 1] : 0);
            cout << ans << endl;
        }
    }

    return 0;
}
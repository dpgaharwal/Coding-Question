/*https://cses.fi/problemset/task/1661*/
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vll arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll sum = 0;
    ll ans = 0;
    map<ll, ll> mp; // Use ordered map instead of unordered map
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ans += mp[sum - x]; // If sum - x is already present in the map, then add its frequency to the answer
        if (sum == x)
            ans++; // If sum is equal to x, then increment the answer
        mp[sum]++;
    }
    cout << ans << '\n';

    return 0;
}
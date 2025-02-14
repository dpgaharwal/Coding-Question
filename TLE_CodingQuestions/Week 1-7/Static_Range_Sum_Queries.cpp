/*https://cses.fi/problemset/task/1646*/
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
    int n, q;
    cin >> n >> q;
    vector<ll> x(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }

    // prefix sum
    for (int i = 1; i <= n; ++i)
    {
        x[i] += x[i - 1];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << x[b] - x[a - 1] << '\n';
    }
    return 0;
}
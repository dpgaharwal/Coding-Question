#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REP_REV(i, a, b) for (int i = a; i >= b; i--)
#define SORT_ALL_ASC(x) sort(ALL(x))
#define SORT_ALL_DESC(x) sort(ALL(x), greater<>())
#define FAST_IO()                \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)

const int MOD = 1e9 + 7;
#define MAX 100000
const int INF = INT_MAX;

void solve()
{
    int n;
    cin >> n;

    map<int, int> factors;

    // Prime Factorization
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        factors[n]++;

    int maxPower = 0;
    for (auto &[prime, power] : factors)
        maxPower = max(maxPower, power);

    vector<int> base(maxPower, 1);

    for (auto &[prime, power] : factors)
    {
        for (int i = 0; i < power; i++)
        {
            base[i] *= prime;
        }
    }

    ll result = accumulate(base.begin(), base.end(), 0LL);
    cout << result << '\n';
}

int main()
{
    FAST_IO();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
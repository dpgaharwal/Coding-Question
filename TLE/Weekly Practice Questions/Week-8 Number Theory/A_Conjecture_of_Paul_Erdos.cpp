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
const int N = 10000007;

bool sieve[N];
int ans[N];

int main()
{
    FAST_IO();
    memset(sieve, 0, sizeof(sieve));
    memset(ans, 0, sizeof(ans));

    REP(i, 2, N)
    {
        if (!sieve[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                sieve[j] = 1;
            }
        }
    }

    for (int x = 1; x <= 5000; x++)
    {
        for (int y = 1; y <= 90; y++)
        {
            int res = x * x + y * y * y * y;
            if (res >= N)
                break;

            if (!sieve[res])
                ans[res] = 1;
        }
    }

    // prefix sum
    for (int i = 1; i < N; i++)
    {
        ans[i] = ans[i] + ans[i - 1];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
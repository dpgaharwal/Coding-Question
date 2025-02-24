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
#define int long long
#include <numeric>

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
void solve()
{
    int X;
    cin >> X;
    int a = 1, b = X;

    for (int i = 1; i * i <= X; i++)
    {
        if (X % i == 0)
        {
            int j = X / i;

            if (lcm(i, j) == X)
            {
                if (max(i, j) < max(a, b))
                {
                    a = i;
                    b = j;
                }
            }
        }
    }

    cout << a << " " << b << endl;
}
int32_t main()
{
    FAST_IO();
    solve();
    return 0;
}
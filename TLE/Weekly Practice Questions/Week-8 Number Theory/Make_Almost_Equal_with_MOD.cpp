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
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long int ans = 2;
    while (true)
    {
        set<long long int> st;
        REP(j, 0, n)
        {
            st.insert(a[j] % ans);
        }
        if (st.size() == 2)
        {
            cout << ans << "\n";
            return;
        }
        ans *= 2;
    }

    cout << ans;
}

int main()
{
    FAST_IO();
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
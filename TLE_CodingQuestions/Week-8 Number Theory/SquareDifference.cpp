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

template <typename T>
void read(T &container)
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        cin >> container[i];
    }
}

template <typename T>
void write(const T &container)
{
    for (const auto &x : container)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    if ((a - b) != 1)
    {
        cout << "NO" << endl;
        return;
    }
    ll num = a + b;
    // we will check whether num is prime or not
    int cnt = 0;
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
            {
                cnt++;
                num /= i;
            }
        }
    }
    if (num > 1)
    {
        cnt++;
    }
    if (cnt == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// Problem Link:https://www.codechef.com/learn/course/bit-manipulation/BITM05/problems/ANDSUBAR

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
    // ... your code logic for a single test case ...
    // long long N;
    // cin >> N;
    // long long ans = 1;

    // for (int i = 1; i < N; i++)
    // {
    //     if ((ans &= i) < 0)
    //     {
    //         ans = i;
    //         continue;
    //     }
    //     ans &= i;
    // }
    // cout << ans << endl;
    int N;
    cin >> N;
    int ans = 0;
    int currPos = 1;
    while (currPos <= N)
    {
        int nxt = min(N, (currPos * 2) - 1);
        ans = max(ans, nxt - currPos + 1);
        currPos *= 2;
    }
    cout << ans << endl;
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
// Problem Link: https://codeforces.com/problemset/problem/1362/B

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
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> originalSet;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        originalSet.insert(v[i]);
    }

    for (int k = 1; k <= 1024; k++)
    {
        set<int> transformedSet;
        for (int num : v)
        {
            transformedSet.insert(num ^ k);
        }
        if (transformedSet == originalSet)
        {
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
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
// Problem Link: https://codeforces.com/problemset/problem/276/C

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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Array to store frequency of indices
    vector<ll> pre(n + 1, 0);

    // Process queries
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        pre[l - 1]++; // Adjust to 0-based index
        if (r < n)
            pre[r]--;
    }

    // Compute prefix sum to get frequency of each index
    for (int i = 1; i < n; i++)
    {
        pre[i] += pre[i - 1];
    }

    // Keep only the first n elements
    pre.resize(n);

    // Sort the array and frequency
    sort(a.begin(), a.end());
    sort(pre.begin(), pre.end());

    // Calculate the maximum sum
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * pre[i];
    }

    cout << ans << endl;
    return 0;
}
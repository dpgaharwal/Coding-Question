// Problem Link: https://codeforces.com/problemset/problem/816/B
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> pre(2000001, 0);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        pre[l]++;
        if (r + 1 < 2000001)
            pre[r + 1]--;
    }

    // Calculate prefix sum of the pre array
    for (int i = 1; i < 2000000; i++)
    {
        pre[i] += pre[i - 1];
    }

    // Calculate the number of times each index is visited
    for (int i = 0; i < 2000000; i++)
    {
        if (pre[i] >= k)
            pre[i] = 1;
        else
            pre[i] = 0;
    }

    // Calculate the prefix sum of the pre array
    for (int i = 1; i < 2000000; i++)
    {
        pre[i] += pre[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << endl;
    }

    return 0;
}
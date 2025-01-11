// Problem Link: https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO22001

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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            pre[i][j] = matrix[i][j] ? 0 : 1;
            if (j > 1)
                pre[i][j] += pre[i][j - 1];
            if (i > 1)
                pre[i][j] += pre[i - 1][j];
            if (i > 1 && j > 1)
                pre[i][j] -= pre[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll countZeros = pre[l2][r2] - pre[l1 - 1][r2] - pre[l2][r1 - 1] + pre[l1 - 1][r1 - 1];
        if (countZeros == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
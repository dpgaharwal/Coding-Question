// Problem Link: https://codeforces.com/problemset/problem/1202/A

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        string x, y;
        cin >> x >> y;
        int pos_y = 0;
        int pos_x = 0;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        for (int i = 0; i < y.size(); i++)
        {
            if (y[i] == '1')
            {
                pos_y = i;
                break;
            }
        }

        for (int i = pos_y; i < x.size(); i++)
        {
            if (x[i] == '1')
            {
                pos_x = i;
                break;
            }
        }

        cout << pos_x - pos_y << endl;
    }
    return 0;
}
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
    ll n, k;
    cin >> n >> k;

    while (k--)
    {
        int digit = n % 10;
        if (digit == 0)
            n /= 10;
        else
            n -= 1;
    }
    cout << n << endl;
    return 0;
}
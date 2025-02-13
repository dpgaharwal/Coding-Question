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

int solve()
{
    int n;
    cin >> n;

    vector<int> prime_factor;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                prime_factor.push_back(i);
            }
        }
    }
    if (n > 1)
    {
        prime_factor.push_back(n);
    }
}
int main()
{

    return 0;
}
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

const int N = 1e7;
int spf[N];

int solve()
{
    int n;
    cin >> n;
    vector<int> prime_factors;
    while (n > 1)
    {
        prime_factors.push_back(spf[n]);
        n /= spf[n];
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return 0;
}
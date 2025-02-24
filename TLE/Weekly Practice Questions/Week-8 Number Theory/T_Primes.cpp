#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REP_REV(i, a, b) for (int i = a; i >= b; i--)
#define SORT_ALL_ASC(x) sort(ALL(x))
#define SORT_ALL_DESC(x) sort(ALL(x), greater<>())
#define FAST_IO()                \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)

const int MOD = 1e9 + 7;
#define MAX 100000
const int INF = INT_MAX;

const int MAX_N = 1e6 + 2;
vector<bool> sieve(MAX_N + 1, false);

int main()
{
    FAST_IO();

    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= MAX_N; i++)
    {
        if (!sieve[i])
        {
            for (int j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;
        }
    }

    int n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 3)
        {
            cout << "NO" << endl;
            continue;
        }
        ll temp = sqrt(arr[i]);
        if (temp * temp == arr[i] && !sieve[temp])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
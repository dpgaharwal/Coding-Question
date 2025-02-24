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

void findKFactors(int n, int k)
{
    vi factors;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }

    if (factors.size() < k)
    {
        cout << -1 << endl;
        return;
    }

    while (factors.size() > k)
    {
        // Merge the last two factors into one
        int a = factors.back();
        factors.pop_back();
        int b = factors.back();
        factors.pop_back();
        factors.push_back(a * b);
    }

    for (int num : factors)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    FAST_IO();
    int n, k;
    cin >> n >> k;

    findKFactors(n, k);
    return 0;
}
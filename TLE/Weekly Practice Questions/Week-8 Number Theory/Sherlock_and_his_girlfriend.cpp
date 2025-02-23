// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ld = long double;
// using vi = vector<int>;
// using vll = vector<ll>;
// using vvi = vector<vi>;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;

// #define ALL(x) (x).begin(), (x).end()
// #define RALL(x) (x).rbegin(), (x).rend()
// #define REP(i, a, b) for (int i = a; i < b; i++)
// #define REP_REV(i, a, b) for (int i = a; i >= b; i--)
// #define SORT_ALL_ASC(x) sort(ALL(x))
// #define SORT_ALL_DESC(x) sort(ALL(x), greater<>())
// #define FAST_IO()                \
//     ios::sync_with_stdio(false); \
//     cin.tie(nullptr);            \
//     cout.tie(nullptr)

// const int MOD = 1e9 + 7;
// #define MAX 100000
// const int INF = INT_MAX;

// int sieve[MAX];

// void solve(int n)
// {
//     REP(i, 2, n + 1)
//     {
//         if (!sieve[i])
//         {
//             for (int j = 2 * i; j <= n + 1; j += i)
//                 sieve[j] = 1;
//         }
//     }
//     if (n > 2)
//     {
//         cout << "2" << endl;
//     }
//     else
//     {
//         cout << "1" << endl;
//     }

//     REP(i, 2, n + 1)
//     {
//         if (!sieve[i])
//             cout << "1 ";
//         else
//             cout << "2 ";
//     }
// }
// int main()
// {
//     FAST_IO();
//     int n;
//     cin >> n;
//     memset(sieve, 0, sizeof(sieve));
//     solve(n);
//     return 0;
// }

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

void solve(int n)
{
    if (n > 2)
    {
        cout << "2" << endl;
    }
    else
    {
        cout << "1" << endl;
    }

    int max_val = n + 1;

    vector<bool> isPrime(max_val + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= max_val; i++)
    {
        if (isPrime[i])
        {
            for (long long j = 1LL * i * i; j <= max_val; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= max_val; i++)
    {
        if (isPrime[i])
        {
            cout << "1 ";
        }
        else
        {
            cout << "2 ";
        }
    }
}
int main()
{
    FAST_IO();
    int n;
    cin >> n;
    solve(n);
    return 0;
}
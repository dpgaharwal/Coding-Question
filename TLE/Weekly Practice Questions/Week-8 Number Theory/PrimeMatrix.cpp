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
const int MAX_LIMIT = 1e5 + 1000;

vector<bool> sieve(int limit)
{
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int next_prime(int num, const vector<bool> &is_prime)
{
    while (true)
    {
        ++num;
        if (is_prime[num])
        {
            return num;
        }
    }
}
int main()
{
    FAST_IO();
    int n, m;
    cin >> n >> m;
    vvi matrix(n, vi(m));

    int max_val = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] > max_val)
            {
                max_val = matrix[i][j];
            }
        }
    }

    int limit = max_val + 1000;
    vector<bool> is_prime = sieve(limit);

    int min_moves = INT_MAX;

    // Check rows
    for (int i = 0; i < n; ++i)
    {
        int moves = 0;
        for (int j = 0; j < m; ++j)
        {
            int num = matrix[i][j];
            if (!is_prime[num])
            {
                moves += next_prime(num, is_prime) - num;
            }
        }
        if (moves < min_moves)
        {
            min_moves = moves;
        }
        if (min_moves == 0)
        {
            break;
        }
    }

    // Check columns
    for (int j = 0; j < m; ++j)
    {
        int moves = 0;
        for (int i = 0; i < n; ++i)
        {
            int num = matrix[i][j];
            if (!is_prime[num])
            {
                moves += next_prime(num, is_prime) - num;
            }
        }
        if (moves < min_moves)
        {
            min_moves = moves;
        }
        if (min_moves == 0)
        {
            break;
        }
    }

    cout << min_moves << endl;
    return 0;
}

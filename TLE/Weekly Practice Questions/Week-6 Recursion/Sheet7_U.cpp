// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U

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

// Using Recursion
int solve(int N, int W, vi &values, vi &weights)
{
    // Base Case
    if (N == 0 || W == 0)
    {
        return 0;
    }

    // Recursive Call
    if (weights[N - 1] <= W)
    {
        return max(values[N - 1] + solve(N - 1, W - weights[N - 1], values, weights), solve(N - 1, W, values, weights));
    }
    else
    {
        return solve(N - 1, W, values, weights);
    }
}
int main()
{
    int N, W;
    cin >> N >> W;
    vi weights(N);
    vi values(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weights[i] >> values[i];
    }
    cout << solve(N, W, values, weights) << endl;
    return 0;
}
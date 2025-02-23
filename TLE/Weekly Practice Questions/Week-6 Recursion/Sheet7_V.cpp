// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
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

// Using recursion
bool f(vector<int> &A, int index, long long currentSum, long long target)
{
    // Base case
    if (index == A.size())
    {
        return currentSum == target;
    }

    // Recursive case
    return f(A, index + 1, currentSum + A[index], target) ||
           f(A, index + 1, currentSum - A[index], target);
}

int main()
{
    int N, X;
    cin >> N >> X;
    vi A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    if (f(A, 1, A[0], X))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
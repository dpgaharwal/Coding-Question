// Problem Link: https://www.geeksforgeeks.org/calculate-xor-1-n/
// Problem Link:https://www.geeksforgeeks.org/find-xor-of-numbers-from-the-range-l-r/
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

int computeXOR(int n)
{
    switch (n % 4)
    {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n + 1;
    case 3:
        return 0;
    }
    return 0;
}

int rangeXOR(int L, int R)
{
    return computeXOR(L - 1) ^ computeXOR(R);
}

int main()
{
    int L = 5, R = 8;
    cout << "XOR from " << L << " to " << R << " is " << rangeXOR(L, R) << endl;
    return 0;
}
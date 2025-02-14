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
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a = 0, d = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
            a++;
        else
            d++;
    }

    if (a > d)
        cout << "Anton" << endl;
    if (a == d)
        cout << "Friendship" << endl;
    if (a < d)
        cout << "Danik" << endl;
    return 0;
}
// Problem Link: https://cses.fi/problemset/task/1622

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

vector<string> allStrings;
// Using Recursion
void solve(int index, int size, vi &freq, string curr)
{
    // Base Case
    if (index == size)
    {
        allStrings.push_back(curr);
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            freq[i]--;
            solve(index + 1, size, freq, curr + char(i + 'a'));
            freq[i]++;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vi f(26);
    for (char c : s)
        f[c - 'a']++;

    solve(0, s.size(), f, "");

    cout << allStrings.size() << endl;

    for (string str : allStrings)
        cout << str << endl;
}
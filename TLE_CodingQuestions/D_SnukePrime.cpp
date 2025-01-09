/*https://atcoder.jp/contests/abc188/tasks/abc188_d*/

/*
// is the constraint of a,b <=1e6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 1;
int diff[N];

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> start(n), end(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i] >> cost[i];
    }

    // Use a difference array technique
    for (int i = 0; i < n; i++) {
        diff[start[i]] += cost[i];
        diff[end[i] + 1] -= cost[i];
    }

    // Accumulate the difference array to get the actual cost at each point
    for (int i = 1; i < N; i++) {
        diff[i] += diff[i - 1];
    }

    // Calculate the total cost with the cap at 'c'
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += min(diff[i], c);
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}

*/

// is the constraint of a,b <=1e9
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int N = 1e6 + 1;
ll diff[N]; // already assign 0 to the elements of the array

int main()
{
    ll n, c;
    cin >> n >> c;

    vector<ll> start(n), end(n), cost(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> start[i] >> end[i] >> cost[i];
    }

    set<int> st;
    for (int i = 0; i < n; ++i)
    {
        st.insert(start[i]);
        st.insert(end[i] + 1);
    }

    map<int, int> mp;
    int idx = 0;
    for (auto x : st)
    {
        mp[x] = idx;
        idx++;
    }
    vector<ll> dif(idx + 1);

    for (int i = 0; i < n; ++i)
    {
        dif[mp[start[i]]] += cost[i];
        dif[mp[end[i] + 1]] -= cost[i];
    }

    // calcualting diff array
    for (int i = 1; i < idx + 1; ++i)
        dif[i] += dif[i - 1];

    ll ans = 0;

    vector<int> a(st.begin(), st.end()); // takes O(N) time for copying from set to vector
    // a -> [2,4,6,9]

    for (int i = 1; i < a.size(); ++i)
    {
        ll days = a[i] - a[i - 1];
        ans += min(dif[i - 1], c) * days;
    }

    cout << ans << endl;
}

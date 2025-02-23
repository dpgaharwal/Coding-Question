// Problem Link: https://www.codechef.com/COOK143A/problems/SEGFAULT
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    unordered_map<int, bool> innocence;

    for (int person = 1; person <= n; ++person)
    {
        int l, r;
        cin >> l >> r;

        if (person >= l && person <= r)
            innocence[person] = 1;

        a[l]++;
        a[r + 1]--;
    }

    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == n - 1 && innocence[i] == 0)
            ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

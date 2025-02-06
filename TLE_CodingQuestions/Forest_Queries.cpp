// https://cses.fi/problemset/task/1652/
// Forest Queries

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    // Create prefix sum array with padding
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    // Read forest and build prefix sum
    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++)
        {
            prefix[i][j] = (row[j - 1] == '*');
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    // Process queries
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int result = prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1 - 1][x2] + prefix[y1 - 1][x1 - 1];
        cout << result << "\n";
    }

    return 0;
}
// Problem Link: https://codeforces.com/problemset/problem/1421/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            int result = a ^ b;
            cout << result << endl;
        }
    }
    return 0;
}
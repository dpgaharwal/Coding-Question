// Problem Link: https://codeforces.com/problemset/problem/276/C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n); // Array elements
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> freq(n + 1, 0); // Difference array for frequency calculation

    // Process each query using the difference array
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        freq[l - 1]++; // Increment at the start of the range
        if (r < n)
            freq[r]--; // Decrement just after the end of the range
    }

    // Convert the difference array into a frequency array using prefix sum
    for (int i = 1; i < n; i++)
    {
        freq[i] += freq[i - 1];
    }

    freq.pop_back();                                // Remove the extra space at the end
    sort(freq.begin(), freq.end(), greater<int>()); // Sort frequencies in descending order
    sort(a.begin(), a.end(), greater<int>());       // Sort array in descending order

    // Calculate the maximum sum
    long long maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum += 1LL * a[i] * freq[i];
    }

    cout << maxSum << endl;

    return 0;
}

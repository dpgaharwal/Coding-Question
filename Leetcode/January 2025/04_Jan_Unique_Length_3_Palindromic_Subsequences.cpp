/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".


Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")


Constraints:

3 <= s.length <= 10^5
s consists of only lowercase English letters.
*/
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

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_set<string> uniquePalindromes;
        int n = s.length();
        vector<vector<int>> left(26, vector<int>(n, 0));
        vector<vector<int>> right(26, vector<int>(n, 0));

        // Fill left array
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
                left[s[i - 1] - 'a'][i] = 1;
            for (int j = 0; j < 26; ++j)
                left[j][i] += (i > 0 ? left[j][i - 1] : 0);
        }

        // Fill right array
        for (int i = n - 1; i >= 0; --i)
        {
            if (i < n - 1)
                right[s[i + 1] - 'a'][i] = 1;
            for (int j = 0; j < 26; ++j)
                right[j][i] += (i < n - 1 ? right[j][i + 1] : 0);
        }

        // Check for palindromic subsequences
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (left[j][i] > 0 && right[j][i] > 0)
                {
                    string palindrome = {char(j + 'a'), s[i], char(j + 'a')};
                    uniquePalindromes.insert(palindrome);
                }
            }
        }

        return uniquePalindromes.size();

        /*TLE Solution
        unordered_set<string> uniquePalindromes;
        int n = s.length();

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (s[i] == s[k])
                    {
                        string palindrome = {s[i], s[j], s[k]};
                        uniquePalindromes.insert(palindrome);
                    }
                }
            }
        }

        return uniquePalindromes.size();
        */
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Solution sol;
    string s;
    cin >> s;
    cout << sol.countPalindromicSubsequence(s) << endl;
    return 0;
}
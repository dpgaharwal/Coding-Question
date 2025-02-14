// Problem: Construct K Palindrome Strings (https://leetcode.com/problems/construct-k-palindrome-strings/)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        // Step 2: Count characters with odd frequency
        int oddCount = 0;
        for (auto &entry : freq)
        {
            if (entry.second % 2 != 0)
            {
                oddCount++;
            }
        }

        // Step 3: Check if we can form k palindromes
        return k <= s.length() && k >= oddCount;
    }
};

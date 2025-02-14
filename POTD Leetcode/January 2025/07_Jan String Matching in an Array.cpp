#include <bits/stdc++.h>
using namespace std;
/*************************Using KMP******************* */
/*
class Solution {
public:
    // Function to compute the LPS array
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Function to perform KMP search
    bool KMPSearch(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();

        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return true; // Pattern found
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false; // Pattern not found
    }

    // Function to find substrings using KMP
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && KMPSearch(words[j], words[i])) {
                    result.push_back(words[i]);
                    break; // Avoid duplicates
                }
            }
        }

        return result;
    }
};
*/

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        // Check each word against every other word
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j && words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break; // Avoid adding duplicates
                }
            }
        }
        return result;
    }
};
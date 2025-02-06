#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> diffIndex;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                diffIndex.push_back(i);
        }

        if (diffIndex.size() == 0)
            return true;

        else if (diffIndex.size() == 2)
        {
            int i = diffIndex[0];
            int j = diffIndex[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }
        else
        {
            return false;
        }
    }
};
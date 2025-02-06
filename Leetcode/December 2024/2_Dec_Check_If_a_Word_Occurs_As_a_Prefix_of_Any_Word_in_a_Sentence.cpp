#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string word;
        vector<string> words;

        while (ss >> word)
        {
            words.push_back(word);
        }

        int n = searchWord.length();
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            string comp = w.substr(0, n);
            if (comp == searchWord)
            {
                return i + 1;
            }
        }

        return -1;
    }
};

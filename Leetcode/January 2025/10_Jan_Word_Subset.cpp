#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
        std::vector<int> maxFreq(26, 0);
        std::vector<std::string> result;

        // Determine the maximum frequency for each character required by words2
        for (const auto &word : words2)
        {
            std::vector<int> freq = countFrequency(word);
            for (int i = 0; i < 26; ++i)
            {
                maxFreq[i] = std::max(maxFreq[i], freq[i]);
            }
        }

        // Check each word in words1
        for (const auto &word : words1)
        {
            std::vector<int> freq = countFrequency(word);
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i)
            {
                if (freq[i] < maxFreq[i])
                {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal)
            {
                result.push_back(word);
            }
        }

        return result;
    }

private:
    std::vector<int> countFrequency(const std::string &word)
    {
        std::vector<int> freq(26, 0);
        for (char c : word)
        {
            ++freq[c - 'a'];
        }
        return freq;
    }
};

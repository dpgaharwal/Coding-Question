class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        // Step 1: Frequency count
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }

        // Step 2: Max heap to get the lexicographically largest characters
        priority_queue<pair<char, int>> maxHeap;
        for (auto &p : freq)
        {
            maxHeap.push({p.first, p.second});
        }

        string result = "";

        while (!maxHeap.empty())
        {
            // Extract the largest available character
            auto [currChar, currCount] = maxHeap.top();
            maxHeap.pop();

            // Check how many times we can add this character (up to
            // repeatLimit)
            int useCount = min(currCount, repeatLimit);
            for (int i = 0; i < useCount; i++)
            {
                result += currChar;
            }

            currCount -= useCount; // Remaining count of the current character

            // If we still have remaining characters, try to "break" the
            // sequence
            if (currCount > 0)
            {
                if (maxHeap.empty())
                {
                    // No other character is available to break the sequence
                    break;
                }

                // Extract the second largest character
                auto [nextChar, nextCount] = maxHeap.top();
                maxHeap.pop();

                // Add one instance of the second largest character to break the
                // sequence
                result += nextChar;
                nextCount--;

                // Push the second largest character back if it still has
                // occurrences
                if (nextCount > 0)
                {
                    maxHeap.push({nextChar, nextCount});
                }

                // Push the current character back for further usage
                maxHeap.push({currChar, currCount});
            }
        }

        return result;
    }
};
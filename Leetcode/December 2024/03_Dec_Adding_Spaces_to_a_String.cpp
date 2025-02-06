class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.length();
        string newstring = "";
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (k < spaces.size() && i == spaces[k])
            {
                newstring += " ";
                k++;
            }
            newstring += s[i];
        }
        return newstring;
    }
};
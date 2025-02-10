#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string clearDigits(string s)
    {
        string st;
        for (auto ch : s)
        {
            if (isdigit(ch))
            {
                if (!st.empty())
                    st.pop_back();
            }
            else
                st.push_back(ch);
        }
        return st;
    }
};
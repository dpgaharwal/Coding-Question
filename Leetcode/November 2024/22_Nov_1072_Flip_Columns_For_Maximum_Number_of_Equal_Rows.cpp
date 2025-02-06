class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (auto &row : matrix)
        {
            string canonicalPattern = "";

            for (int cell : row)
            {
                canonicalPattern += (cell ^ row[0]) ? '1' : '0';
            }

            patternCount[canonicalPattern]++;
            maxRows = max(maxRows, patternCount[canonicalPattern]);
        }

        return maxRows;
    }
};

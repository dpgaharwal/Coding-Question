class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }

        for (int col = 0; col < m; ++col)
        {
            int pointer = n - 1;
            for (int row = n - 1; row >= 0; --row)
            {
                if (rotatedBox[row][col] == '*')
                {
                    pointer = row - 1;
                }
                else if (rotatedBox[row][col] == '#')
                {
                    if (pointer != row)
                    {
                        rotatedBox[pointer][col] = '#';
                        rotatedBox[row][col] = '.';
                    }
                    --pointer;
                }
            }
        }

        return rotatedBox;
    }
};

class Solution
{
public:
    void helper(int m, int n, vector<vector<int>> &map, int x, int y)
    {
        // Up (North)
        for (int i = x - 1; i >= 0; i--)
        {
            if (map[i][y] == -1 || map[i][y] == 0)
                break;
            if (map[i][y] == 1)
                map[i][y] = 2;
        }
        // Down (South)
        for (int i = x + 1; i < m; i++)
        {
            if (map[i][y] == -1 || map[i][y] == 0)
                break;
            if (map[i][y] == 1)
                map[i][y] = 2;
        }
        // Left (West)
        for (int j = y - 1; j >= 0; j--)
        {
            if (map[x][j] == -1 || map[x][j] == 0)
                break;
            if (map[x][j] == 1)
                map[x][j] = 2;
        }
        // Right (East)
        for (int j = y + 1; j < n; j++)
        {
            if (map[x][j] == -1 || map[x][j] == 0)
                break;
            if (map[x][j] == 1)
                map[x][j] = 2;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {

        vector<vector<int>> map(m, vector<int>(n, 1));

        // Mark walls as -1
        for (const auto &wall : walls)
        {
            int x = wall[0], y = wall[1];
            map[x][y] = -1;
        }

        // Mark guards as 0
        for (const auto &guard : guards)
        {
            int x = guard[0], y = guard[1];
            map[x][y] = 0;
        }

        // Process each guard to mark guarded cells
        for (const auto &guard : guards)
        {
            int x = guard[0], y = guard[1];
            helper(m, n, map, x, y);
        }

        // Count unguarded cells (cells with value 1)
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string start;
        for (const auto &row : board)
            for (int num : row)
                start += to_string(num);

        string target = "123450";
        vector<vector<int>> neighbors = {
            {1, 3},    // index 0
            {0, 2, 4}, // index 1
            {1, 5},    // index 2
            {0, 4},    // index 3
            {1, 3, 5}, // index 4
            {2, 4}     // index 5
        };

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty())
        {
            auto [state, moves] = q.front();
            q.pop();

            if (state == target)
                return moves;

            int zeroPos = state.find('0');
            for (int neighbor : neighbors[zeroPos])
            {
                string newState = state;
                swap(newState[zeroPos], newState[neighbor]);

                if (visited.count(newState) == 0)
                {
                    q.push({newState, moves + 1});
                    visited.insert(newState);
                }
            }
        }
        return -1; // If the goal state is unreachable
    }
};
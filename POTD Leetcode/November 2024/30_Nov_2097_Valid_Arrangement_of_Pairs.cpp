#include <vector>
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, deque<int>> graph;
        unordered_map<int, int> in_degree, out_degree;

        for (auto &pair : pairs)
        {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            out_degree[start]++;
            in_degree[end]++;
        }

        int start_node = pairs[0][0];
        for (auto &[node, _] : graph)
        {
            if (out_degree[node] - in_degree[node] == 1)
            {
                start_node = node;
                break;
            }
        }

        vector<int> eulerian_path;
        stack<int> stack;
        stack.push(start_node);

        while (!stack.empty())
        {
            int current = stack.top();
            if (!graph[current].empty())
            {
                stack.push(graph[current].front());
                graph[current].pop_front();
            }
            else
            {
                eulerian_path.push_back(current);
                stack.pop();
            }
        }

        reverse(eulerian_path.begin(), eulerian_path.end());

        vector<vector<int>> result;
        for (size_t i = 0; i < eulerian_path.size() - 1; ++i)
        {
            result.push_back({eulerian_path[i], eulerian_path[i + 1]});
        }

        return result;
    }
};

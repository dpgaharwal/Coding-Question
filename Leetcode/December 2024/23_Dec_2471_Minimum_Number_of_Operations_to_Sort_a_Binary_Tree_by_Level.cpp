/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> sortedArr(n);
        for (int i = 0; i < n; i++)
        {
            sortedArr[i] = {arr[i], i};
        }
        sort(sortedArr.begin(), sortedArr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] || sortedArr[i].second == i)
            {
                continue;
            }

            int cycleSize = 0;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                j = sortedArr[j].second;
                ++cycleSize;
            }

            if (cycleSize > 1)
            {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }

    int minimumOperations(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> levelValues;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                levelValues.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            totalSwaps += minSwaps(levelValues);
        }
        return totalSwaps;
    }
};
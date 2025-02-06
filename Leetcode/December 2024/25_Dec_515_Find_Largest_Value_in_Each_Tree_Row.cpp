/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        // use bfs
        // initialize result array
        // maintain a temp priority after traverse the row add max number to
        // result vector
        if (!root)
            return {};

        vector<int> result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int level_size = q.size();
            int max_val = INT_MIN;

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                max_val = max(max_val, node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            result.push_back(max_val);
        }

        return result;
    }
};
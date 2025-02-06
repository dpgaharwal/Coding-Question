class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return nullptr;

        // Helper function to reverse the odd levels
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<TreeNode *> currentLevelNodes;

            // Process all nodes at the current level
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Reverse values at odd levels
            if (level % 2 == 1)
            {
                int n = currentLevelNodes.size();
                for (int i = 0; i < n / 2; ++i)
                {
                    swap(currentLevelNodes[i]->val, currentLevelNodes[n - 1 - i]->val);
                }
            }

            ++level;
        }

        return root;
    }
};

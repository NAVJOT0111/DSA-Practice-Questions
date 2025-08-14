class Solution
{
public:
    int width(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = 0;
        // Create a queue to perform level-order
        // traversal, where each element is a pair
        // of TreeNode* and its position in the level
        queue<pair<TreeNode *, int>> q;
        // push the root node and its position 0 into the array
        q.push({root, 0});

        // perform the level order traversal
        while (!q.empty())
        {
            // number of nodes at current level
            int size = q.size();

            // position of front node in the current level
            int mmin = q.front().second;

            // store the first and last position of nodes in current lveel
            for (int i = 0; i < size; i++)
            {
                // calculates the current position relative to the minimum position in the level
                int cur_id = q.front().second - mmin;
                // get the current node
                TreeNode *node = q.front().first;
                // pop the front node
                q.pop();

                // If this is the first node in the level, update the 'first' variable
                if (i == 0)
                {
                    first = cur - id;
                }

                // if its last node, update the last variable
                if (i == size - 1)
                {
                    last = cur_id;
                }

                // Enqueue the left child of the
                // current node with its position
                if (node->left)
                {
                    q.push({node->left, cur_id * 2 + 1});
                }

                // Enqueue the right child of the
                // current node with its position
                if (node->right)
                {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }
             // Update the maximum width by calculating
            // the difference between the first and last
            // positions, and adding 1
            ans = max(ans, last - first + 1);
        }
        // Return the maximum
        // width of the binary tree
        return ans;
    }
};
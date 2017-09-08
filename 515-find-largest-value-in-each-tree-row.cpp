/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }
        queue<TreeNode*> node_queue;
        TreeNode* start = root;
        TreeNode* end = root;
        TreeNode* cur_end = NULL;
        node_queue.push(root);
        int cur_max = INT_MIN;
        while (!node_queue.empty())
        {
            TreeNode* p = node_queue.front();
            node_queue.pop();
            if (p == start)
            {
                if (p->left != NULL)
                {
                    start = p->left;
                }
                else if (p->right != NULL)
                {
                    start = p->right;
                }
                else if (!node_queue.empty())
                {
                    start = node_queue.front();
                }
            }
            cur_max = max(cur_max, p->val);
            if (p->left != NULL)
            {
                cur_end = p->left;
                node_queue.push(p->left);
            }
            if (p->right != NULL)
            {
                cur_end = p->right;
                node_queue.push(p->right);
            }
            if (p == end)
            {
                res.push_back(cur_max);
                cur_max = INT_MIN;
                end = cur_end;
                cur_end = NULL;
            }
        }
        return res;
    }
};

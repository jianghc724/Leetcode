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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        if (isBalanced(root->left) && isBalanced(root->right))
        {
            int l_height = height(root->left);
            int r_height = height(root->right);
            if (l_height == r_height || l_height == r_height + 1 || l_height == r_height - 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
    int height(TreeNode* root)
    {
        if (root)
        {
            return (max(height(root->left), height(root->right)) + 1);
        }
        else
        {
            return 0;
        }
    }
};

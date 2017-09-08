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
    int res;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        cal(root);
        return res;
    }
    
    int cal(TreeNode* p)
    {
        if (p == NULL)
        {
            return 0;
        }
        
        int l = cal(p->left);
        int r = cal(p->right);
        
        res = max(max(max(res, p->val), max(p->val + l, p->val + r)), p->val + l + r);
        return max(max(p->val, p->val + l), p->val + r);
    }
};

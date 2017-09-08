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
    int pre;
    int res;
    bool isSet;
    
    int getMinimumDifference(TreeNode* root) {
        res = INT_MAX;
        pre = 0;
        isSet = false;
        cal(root);
        return res;
    }
    
    void cal(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        
        cal(root->left);
        if (isSet)
        {
            res = min(res, root->val - pre);
        }
        pre = root->val;
        isSet = true;
        cal(root->right);
    }
};

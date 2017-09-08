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
    map<int, int> num_map;
    
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
        {
            return false;
        }
        if (findTarget(root->left, k)) return true;
        if (num_map.find(root->val) != num_map.end()) return true;
        num_map.insert(make_pair(k - root->val,1));
        if (findTarget(root->right, k)) return true;
        return false;
    }
};

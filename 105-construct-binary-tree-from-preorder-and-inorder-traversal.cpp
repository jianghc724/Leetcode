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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (size == 0) {
            return NULL;
        }
        TreeNode* p = new TreeNode(preorder[0]);
        int i = 0;
        for (auto x : inorder) {
            if (x == preorder[0]) {
                break;
            }
            i++;
        }
        vector<int> pre_1(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> in_1(inorder.begin(), inorder.begin() + i);
        vector<int> pre_2(preorder.begin() + i + 1, preorder.end());
        vector<int> in_2(inorder.begin() + i + 1, inorder.end());
        p->left = buildTree(pre_1, in_1);
        p->right = buildTree(pre_2, in_2);
        return p;
    }
};

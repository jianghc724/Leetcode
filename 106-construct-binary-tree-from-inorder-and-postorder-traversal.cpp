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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        if (size == 0) {
            return NULL;
        }
        TreeNode* p = new TreeNode(postorder[size - 1]);
        int i = 0;
        for (auto x : inorder) {
            if (x == postorder[size - 1]) {
                break;
            }
            i++;
        }
        vector<int> in_1(inorder.begin(), inorder.begin() + i);
        vector<int> post_1(postorder.begin(), postorder.begin() + i);
        vector<int> in_2(inorder.begin() + i + 1, inorder.end());
        vector<int> post_2(postorder.begin() + i, postorder.end() - 1);
        p->left = buildTree(in_1, post_1);
        p->right = buildTree(in_2, post_2);
        return p;
    }
};

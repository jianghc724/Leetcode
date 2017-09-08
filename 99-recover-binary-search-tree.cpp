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
    TreeNode* first;
    TreeNode* second;
    int prev;
	TreeNode* prev_node;
    
    void find(TreeNode* p) {
        if (p == NULL)
        {
            return;
        }
        find(p->left);
        if (prev > p->val)
        {
            if (first == NULL)
            {
				first = prev_node;
                second = p;
            }
            else
            {
                second = p;
            }
        }
        prev = p->val;
		prev_node = p;
        find(p->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = NULL;
        second = NULL;
        prev = INT_MIN;
		prev_node = NULL;
        
        find(root);
        
        if (first != NULL && second != NULL)
        {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};

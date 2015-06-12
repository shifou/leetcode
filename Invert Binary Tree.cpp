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
    void rev(TreeNode * root)
    {
        if(root==0)
            return;
        swap(root->left,root->right);
        rev(root->left);
        rev(root->right);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        rev(root);
        return root;    
    }
};
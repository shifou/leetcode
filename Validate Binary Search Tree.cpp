class Solution {
public:
bool mlx(TreeNode* root,int l,int r)
{
    if(root==0) return true;
    return root->val>l && root->val <r && mlx(root->left,l,root->val) && mlx(root->right,root->val,r);
}
    bool isValidBST(TreeNode *root) {
        return mlx(root,-9999999,999999);
    }
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        if(root->left==NULL)
            return 1+minDepth(root->right);
        else if(root->right==NULL)
            return 1+minDepth(root->left);
        else
         {
        int ll= minDepth(root->left)+1;
        int rr= minDepth(root->right)+1;
            return min(ll,rr) ;
         }
    }
    
};
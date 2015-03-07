class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root->left==0&&root->right==0) return root->val;
        int sum=root->val;
        mlx(root,sum);
        return sum;
        
    }
    int mlx(TreeNode* root, int &ans)
    {
        if(root==0) return 0;
        
         int h1=mlx(root->left,ans);
         int h2=root->val;
         int h3=mlx(root->right,ans);
         if(max(h1,h3)>0) h2+=max(h1,h3);
         int hold=root->val;
         if(h1>0) hold+=h1;
         if(h3>0) hold+=h3;
         ans=max(hold,ans);
         return h2;
    }
};
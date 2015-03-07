class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root)
            return;
        vector<TreeNode*> fk;
        mlx(fk,root);
        for(int i=0;i<fk.size()-1;i++)
        {
            fk[i]->left=NULL;
            fk[i]->right=fk[i+1];
        }
    }
    void mlx(vector<TreeNode*> & ans, TreeNode* now)
    {
        if(!now)
            return;
        ans.push_back(now);
        if(now->left)
            mlx(ans,now->left);
        if(now->right)
            mlx(ans,now->right);
    }
};
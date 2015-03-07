class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int ans=0;
        mlx(ans, root,0);
        return ans;
    }
    void mlx(int &sum, TreeNode* now, int hold)
    {
        if(now==NULL)
            return;
        if(now->left==NULL && now->right==NULL)
        {
            hold=hold*10+now->val;
            sum+=hold;
            return;
        }
        if(now->left)
            mlx(sum,now->left, hold*10+now->val);
        if(now->right)
            mlx(sum,now->right, hold*10+now->val);
    }
};
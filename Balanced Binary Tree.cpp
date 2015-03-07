class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
     flag=true;
     fun(root);
     return flag;
    }
    int fun(TreeNode* now)
    {
        if(now==NULL)
            return 0;
        int l = 1+fun(now->left);
        int r = 1+fun(now->right);
        if(abs(l-r)>1)
            flag=false;
        return max(l,r);
    }
};
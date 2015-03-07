class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        else
            print(ans,root);
        return ans;
        
    }
    void print(vector<int> &a , TreeNode * now)
    {
        if(now==NULL)
            return;
        if(now->left)
            print(a,now->left);
        if(now->right)
            print(a,now->right);
        a.push_back(now->val);
    }
};
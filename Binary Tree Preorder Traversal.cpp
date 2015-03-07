class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> q;
        TreeNode * h=root;
        if(h==NULL)
            return ans;
        else
           print(ans,root);
        return ans;
    }
    void print(vector<int>&a, TreeNode *now)
    {
        if(now==NULL)
            return;
        a.push_back(now->val);
        print(a,now->left);
        print(a,now->right);
    }
};
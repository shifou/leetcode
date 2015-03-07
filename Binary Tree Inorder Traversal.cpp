class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        print(root, ans);
        return ans;
    }
    void print(TreeNode* now, vector<int>&res)
    {
        if(now==NULL)
            return;
       
        print(now->left,res);
         res.push_back(now->val);
        print(now->right,res);
    }
};
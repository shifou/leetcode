/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            vector<TreeNode*> hold;
            while(!q.empty())
            {
                TreeNode* tmp = q.front();
                q.pop();
                hold.push_back(tmp);
            }
            ans.push_back(hold.back()->val);
            for(int i=0;i<hold.size();i++)
            {
                if(hold[i]->left)
                q.push(hold[i]->left);
                if(hold[i]->right)
                q.push(hold[i]->right);
            }
            
        }
        return ans;
    }
};
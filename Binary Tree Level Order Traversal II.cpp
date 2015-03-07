class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
         vector<vector<int> > ans;
         if(root==NULL)
            return ans;
         stack<vector<int> > hold;
         queue<TreeNode*> q;
         q.push(root);
         while(!q.empty())
         {
             vector<TreeNode*> nodes;
             vector<int> temp;
             while(!q.empty())
             {
                TreeNode*now = q.front();
                q.pop();
                nodes.push_back(now);
             }
             for(int i=0;i<nodes.size();i++)
             {
                 temp.push_back(nodes[i]->val);
                 if(nodes[i]->left)
                    q.push(nodes[i]->left);
                if(nodes[i]->right)
                    q.push(nodes[i]->right);
             }
             hold.push(temp);
         }
         while(!hold.empty())
         {
             vector<int> tt= hold.top();
             hold.pop();
             ans.push_back(tt);
         }
         return ans;
    }
};
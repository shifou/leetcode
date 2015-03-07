class Solution {
public:
  void mlx(vector<vector<int> > &ans, vector<int> hold, TreeNode *root, int now, int & sum)
  {
      if(now==sum)
      {
          if(root->left==0 && root->right==0) ans.push_back(hold);
          //return;
      }
      if(root->left!=0 ) 
      {
          hold.push_back(root->left->val);
          mlx(ans, hold,root->left, now+root->left->val,sum);
          hold.pop_back();
      }
       if(root->right!=0 ) 
      {
          hold.push_back(root->right->val);
          mlx(ans, hold,root->right, now+root->right->val,sum);
          hold.pop_back();
      }
      
  }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> hold;
        if(root==0)
         return ans;
        hold.push_back(root->val);
        mlx(ans,hold,root,root->val,sum);
        return ans;
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

    if(root==NULL)
        return true;
        TreeNode* hehe= (struct TreeNode*)malloc(sizeof(struct TreeNode));
        hehe->val=-99999999;
        hehe->left=NULL;
        hehe->right=NULL;
        queue<TreeNode*> q1;
         queue<TreeNode*> q2;
         if(root->left)
            q1.push(root->left);
         if(root->right)
            q2.push(root->right);
         while(!q1.empty() && !q2.empty() && q1.size()==q2.size())
         {
             TreeNode* h1=q1.front();
             q1.pop();
             TreeNode* h2=q2.front();
             q2.pop();
             if(h1->val!=h2->val)
                return false;
             if(h1->left) q1.push(h1->left);
              if(h2->right) q2.push(h2->right);
              if(q1.size()!=q2.size())
                return false;
             if(h1->right) q1.push(h1->right);
             if(h2->left) q2.push(h2->left);
             if(q1.size()!=q2.size())
             return false;
         }
        if(q1.empty()&&q2.empty())
            return true;
        else
            return false;
    }
};
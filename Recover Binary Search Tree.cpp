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

    void recoverTree(TreeNode *root) {
        if(root==0||(root&&root->left==0&&root->right==0))
           return;
        TreeNode * cur=root,*ft=0,*sec=0,*pre=0;
        while(cur)
        {
            if(cur->left==0)
            {
                if(pre && pre->val>cur->val)
                {
                        if(ft==0)
                            ft=pre;
                        sec=cur;
                }
                pre= cur;
               cur=cur->right;
            }
            else
            {
                TreeNode * hold = cur->left;
                while(hold->right&&hold->right!=cur)
                   hold=hold->right;
                if(hold->right)
                {
                    hold->right=0;
                     if(pre && pre->val>cur->val)
                    {
                        if(ft==0)
                            ft=pre;
                        sec=cur;
                    }
                     pre= cur;
                    cur=cur->right;
                }
                else
                {
                    hold->right=cur;
                    cur=cur->left;
                }
            }
        }
        //   0    1
        // 1        0
        int fk = ft->val;
        ft->val=sec->val;
        sec->val=fk;
    }
};
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
unordered_map<int,int> mpin;
TreeNode * build(vector<int> &pre, vector<int> &in,int l,int ll,int rr)
{
    /*
    preorder:  {7}, {10,4,3,1}, {2,8,11}
    inorder:   {4,10,3,1}, {7}, {11, 8,2}
    preorder: {10}, {4}, {3,1} 
    inorder:  {4}, {10}, {3,1}  
    */
    if(ll>rr)
        return 0;
    TreeNode *cur = new TreeNode(pre[l]);
    if(ll==rr)
       return cur;
    int iid = mpin[pre[l]];
    cur->left=build(pre,in,l+1,ll,iid-1);
    cur->right = build(pre,in,l+iid-ll+1,iid+1,rr);
    return cur;
}
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        
        if(pre.size()!=in.size())
          return 0;
         else
         {
             for(int i=0;i<in.size();i++)
            {
                mpin[in[i]]=i;
            }
           return build(pre,in,0,0,pre.size()-1);
         }
             
    }
};
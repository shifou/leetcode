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
TreeNode * build(vector<int> &post, vector<int> &in,int r,int ll,int rr)
{
    /*
    in-order:   4 2 5  (1)  6 7 3 8
    post-order: 4 5 2  6 7 8 3  (1)
                0 1 2  3 4 5 6  7
    */
    if(ll>rr)
        return 0;
    TreeNode *cur = new TreeNode(post[r]);
    if(ll==rr)
       return cur;
    int iid = mpin[post[r]];
    cur->left=build(post,in,r-(rr-iid)-1,ll,iid-1);
    cur->right = build(post,in,r-1,iid+1,rr);
    return cur;
}
    TreeNode *buildTree(vector<int> &in, vector<int> &post) {
        
        if(post.size()!=in.size())
          return 0;
         else
         {
             for(int i=0;i<in.size();i++)
            {
                mpin[in[i]]=i;
            }
           return build(post,in,in.size()-1,0,in.size()-1);
         }
             
    }
};
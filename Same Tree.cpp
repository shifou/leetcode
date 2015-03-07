class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
       if(q == NULL && p == NULL)
        return true;
        if(p==NULL || q == NULL)
        return false;
        if(q->val == p->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else return false;
        
    }
};
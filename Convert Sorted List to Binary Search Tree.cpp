class Solution {
public:
    ListNode *cur;
    // 1 2 3 4
    //   2          4          5
    // 1   3      2   1     2    2
    //       4
    TreeNode * mlx(int pos)
    {
        if(!pos)
           return NULL;
        TreeNode * left = mlx(pos/2);
        TreeNode* root = new TreeNode(cur->val);
        cur=cur->next;
        TreeNode * right = mlx(pos-1-pos/2);
        root->left =left;
        root->right = right;
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        cur=head;
        while(cur)
        {
            len++;
            cur=cur->next;
        }
        cur=head;
        return mlx(len);
    }
};
public class Solution {
    TreeNode *upsideDownBinaryTree(TreeNode *root)  {
        TreeNode *p = root, *parent=0 , *parentRight=0;
        while (p) {
            TreeNode *next= p->left;
            p->left = parentRight;
            parentRight = p->right;
            p->right ＝ parent;
            parent = p;
            p = next;
        }
        return parent;
    }
}
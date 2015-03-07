class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root ==NULL)
            return 0;
        int dl = 1+maxDepth(root->left);
        int dr = 1+maxDepth(root->right);
        return max(dl,dr);
    }
};
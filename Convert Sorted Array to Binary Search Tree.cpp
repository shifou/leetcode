class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = num.size();
         
        TreeNode* root = fun(num, 0, size);
        return root;
    }
   //1 2 3 4 5
   // 0 1 2 3 4
    
    TreeNode* fun(vector<int> &num, int left, int right)
    {
        if(left >= right || right >num.size() || right <0)
            return NULL;
        int mid = (left+right)>>1;
       TreeNode*now = new TreeNode(num[mid]);
        now->left=fun(num, left, mid);
        now->right =fun(num, mid+1, right);
        return now;
    }
};
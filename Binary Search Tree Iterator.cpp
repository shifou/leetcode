/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
stack<TreeNode*> cur;
    BSTIterator(TreeNode *root) {
        TreeNode* hold=root;
        while(hold)
        {
            cur.push(hold);
            hold=hold->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !cur.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* hold=cur.top();
        cur.pop();
        int res=hold->val;
        if(hold->right)
        {
            hold=hold->right;
              while(hold)
        {
            cur.push(hold);
            hold=hold->left;
        }
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
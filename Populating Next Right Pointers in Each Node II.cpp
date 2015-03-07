class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        queue<TreeLinkNode*> q;
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
         //puts("-----");
        while(!q.empty())
        {
            vector<TreeLinkNode*> hold;
            while(!q.empty()) 
            {
                hold.push_back(q.front());
                q.pop();
            }
            for(int i=0;i<hold.size();i++)
            {
                if(hold[i]->left) q.push(hold[i]->left);
                if(hold[i]->right) q.push(hold[i]->right);
                if(i<hold.size()-1)
                    hold[i]->next=hold[i+1];
            }
        }
    }
};
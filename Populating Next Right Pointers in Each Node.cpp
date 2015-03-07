class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
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
       /*
        TreeLinkNode* temp = root;
        while(temp)
        {
            TreeLinkNode *hold = temp;
            while(hold)
            {
                printf("%d ",hold->val);
                hold= hold->next;
            }
            puts("");
            temp= temp->left;
        }
        */
    }
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
       vector<vector<int> > ans;
     int o1=0,o2=0;
        if(root==0)
          return ans;
     ok hold;
     hold.node=root;
     hold.ll=0;
     queue<int> f1;
     stack<int> f2;
     //f1.push(root->val);
     vector<queue<int> > h1;
     //h1.push(f1);
     vector<stack<int> >h2;
     queue<ok> qq;
     qq.push(hold);
     int le=1;
     while(!qq.empty())
     {
         ok temp=qq.front();
         qq.pop();
         if(temp.ll&1)
            f2.push(temp.node->val);
        else
            f1.push(temp.node->val);
         if(temp.ll>=le)
         {
            
             if(le&1)
             {
                 h1.push_back(f1);
                 while (!f1.empty())
                    f1.pop();
             }
             else
             {
                 h2.push_back(f2);
                 while (!f2.empty())
                    f2.pop();
             }
              le++;
         }
         if(temp.node->left!=0)
         {
             hold.node=temp.node->left;
             hold.ll=temp.ll+1;
             qq.push(hold);
         }
         if(temp.node->right!=0)
         {
             hold.node=temp.node->right;
             hold.ll=temp.ll+1;
             qq.push(hold);
         }
     }
   if(le&1)
             {
                 if(!f1.empty())
                 h1.push_back(f1);
                 while (!f1.empty())
                    f1.pop();
                 }
             else
             {
                 if(!f2.empty())
                 h2.push_back(f2);
                 while (!f2.empty())
                    f2.pop();
                  
             
             }
    
     for(int i=1;i<=le;i++)
     {
         if(i&1)
         {
             vector<int> hold;
             while(!h1[o1].empty())
             {
                 hold.push_back(h1[o1].front());
                 h1[o1].pop();
             }
             ans.push_back(hold);
             o1++;
         }
         else
         {
             vector<int> hold;
             while(!h2[o2].empty())
             {
                 hold.push_back(h2[o2].top());
                 h2[o2].pop();
             }
             ans.push_back(hold);
             o2++;
         }
     }
     return ans;
    }
};
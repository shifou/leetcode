class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        ListNode* ans=NULL,*hold=NULL,*now=NULL;
        
        priority_queue<ListNode * , vector<ListNode*>,cmp> q;
        for(int i=0;i<lists.size();i++)
           if(lists[i])
            q.push(lists[i]);
        while(!q.empty())
        {
            if(q.size()==1)
            {
                hold=q.top();
                q.pop();
                if(ans==NULL)
                    {ans=hold;
                    now=ans;}
                else
                    now->next=hold;
                break;
            }
            hold = q.top();
            q.pop();
            if(ans==NULL)
            {
                ans= hold;
                now=ans;
            }
            else
            {
                now->next=hold;
                now= now->next;
            }
            if(hold->next)
                q.push(hold->next);
        }
        return ans;
    }
};
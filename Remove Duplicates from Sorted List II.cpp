class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==0)
           return 0;
        if(head->next==0)
           return head;
           ListNode *ans=0;
           ListNode * cur=0;
         ListNode *it=head;
         while(it)
         {
             ListNode * tmp=it->next;
             if(tmp==0)
             {
                if(ans==0)
                   cur=ans=it;
                  else{
                    cur->next=it;
                   cur=cur->next;
                }
                break;
             }
             while(tmp&& tmp->val==it->val)  tmp=tmp->next;
             if(tmp==0) 
             {
                 if(ans!=0)
                  cur->next=0;
                 break;
             }
             if(tmp==it->next)
             {
                if(ans==0)
                    cur=ans=it;
                else{
                    cur->next=it;
                   cur=cur->next;
                }
             }
            it=tmp;
         }
         return ans;
    }
};
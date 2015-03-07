class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==0)
           return 0;
        ListNode *h1=0;
        ListNode * ans=0;
        ListNode * ans2=0;
        ListNode * h2= 0;
        ListNode * pt= head;
        while(pt)
        {
            if(pt->val<x)
            {
                if(h1==0)
                {
                    ans=pt;
                    h1=pt;
                }
                else
                {
                    h1->next=pt;
                    h1=h1->next;
                }
            }
            else
            {
                if(h2==0)
                {
                    ans2=pt;
                    h2=pt;
                }
                else
                {
                 h2->next=pt;
                 h2=h2->next;
                }
            }
            pt=pt->next;
        }
        if(h2)
         h2->next=0;
        if(h1)
        {
          h1->next=ans2;
          //h2->next=0;
        return ans;
        }
        else 
        return ans2;
    }
};
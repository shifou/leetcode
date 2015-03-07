class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ct=0;
        ListNode* h1,*h2,*pre;
        h1=h2=pre=head;
        if(head->next==NULL && n==1)
            return NULL;
        int flag=0;
        vector<ListNode*> hh;
       
        while(h1)
        {
             hh.push_back(h1);
            if(flag==0)
            {
                if(ct==n)
                {
                   h2=hh[hh.size()-n];
                   if(h2!=head)
                    pre=hh[hh.size()-n-1];
                    else
                    {
                        pre=head;
                   h2=h2->next;
                    }
                   flag=1;
                }
                 ct++;
            }
            else
            {
                h2=h2->next;
                pre=pre->next;
            }
            h1=h1->next;
        }
        if(pre!=h2)
        pre->next=h2->next;
        else
            head=head->next;
        return head;
    }
};
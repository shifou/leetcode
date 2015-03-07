class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode fei(0),*hold=&fei;
        fei.next=head;
        // 1 2 3 4 5
        for(int i=0;i<m-1;i++)
            hold=hold->next;
        
        ListNode *cur= hold->next;
        // hold 1 cur 2
        for(int i=m;i<n;i++)
        {
             //1 2 3 4
             // 1 3 2 4
            ListNode* kk= cur->next;
            cur->next=kk->next;
            kk->next=hold->next;
            hold->next=kk;
            //cur->next=kk;
        }
        return fei.next;
    }
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==0 || head->next==0)
          return head;
        int i=0;
        ListNode * hold=head;
        ListNode * pt=head;
        ListNode * nt=head;
        while(nt)
        {
            i++;
            nt=nt->next;
        }
    
        k%=i;
        i=0;
         if(k==0)
          return head;
        nt=head;
        
        while(i<k)
        {
            nt=nt->next;
            i++;
        }
       
        while(nt->next)
        {
            pt=pt->next;
            nt=nt->next;
        }
        ListNode * hh=pt->next;
        pt->next=0;
        nt->next=head;
        return hh;
    }
};
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
      if(head==0 || head->next==0 ||k<=1)
         return head;
    
      ListNode * nh =new ListNode(0);
      nh->next=head;
      ListNode * cur=head,*pre=nh;
      int i=0;
      while(cur)
      {
          //0 1 2 3
          i++;
          if(i%k==0)
          {
              // 0 1 2 3
              // 0 2 1 3 4
              // 0 3 2 1 4
            ListNode * last=pre->next; //1
            ListNode * tmp=pre->next->next;//2
            for(int ct=0;ct<k-1;ct++)
            {
               ListNode * hold=tmp->next;
               last->next=hold;
               tmp->next=pre->next;
               pre->next=tmp;
               
               tmp=hold;
            }
            pre=last;
            cur=pre->next;
          }
          else 
          cur=cur->next;
      }
      return nh->next;
    }
};
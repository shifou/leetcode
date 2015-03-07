class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
       ListNode *h1,*h2,*temp,*pre;
       h1=h2=temp=pre=head;
       while(temp)
       {
           h1=temp;
           h2=temp->next;
           if(h2==NULL)
            break;
           h1->next=h2->next;
           h2->next=h1;
           if(pre!=head)
              pre->next=h2;
            else
                head=h2;
            temp=h1;
           pre=temp;
          temp=temp->next;
       }
        return head;
    }
};
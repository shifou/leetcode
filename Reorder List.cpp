class Solution {
public:
    void reorderList(ListNode *head) {
        if(head==0 || head->next==0 || head->next->next==0)
          return;
        ListNode * slow=head;
        ListNode *fast=head;
        while(fast->next)
        {
            fast=fast->next;
            if(fast->next==0) break;
            fast=fast->next;
             slow=slow->next;
        }
        ListNode *head2=slow->next;
        slow->next=0;
        ListNode * head3=head2;
        if(head2->next!=0)
        {
            ListNode * temp;
            ListNode* post=head2;
            ListNode* it=head2->next;
            post->next=0;
            while(it)
            {
                    temp=it->next;
                    it->next=post;
                    post=it;
                    it=temp;
            }
            head3=post;
        }
        ListNode* it2=head;
        ListNode* it3=head3;
        while(it2)
        {
            if(it3==0) break;
            ListNode* temp=it2->next;
            it2->next=it3;
            ListNode* tmp2=it3->next;
            it3->next=temp;
            it3=tmp2;
            it2=temp;
        }
    }
};
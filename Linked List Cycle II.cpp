class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL|| head->next==NULL)
         return NULL;
        ListNode * slow=head, *fast=head->next->next;
        while(slow!=fast)
        {
            slow=slow->next;
            if(!fast || fast->next==NULL) return NULL;
            fast=fast->next->next;
        }
        int len=1;
        slow=slow->next;
        while(slow!=fast)
        {
            len++;
            slow=slow->next;
        }
        slow=fast=head;
        while(len--)
        {
            fast=fast->next;
        }
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
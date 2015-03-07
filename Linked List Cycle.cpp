class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *h1= head;
        ListNode *h2=head;
        while(h2&&h2->next)
        {
            h2=h2->next->next;
            h1=h1->next;
            if(h1==h2)
                return 1;
        }
            return 0;
    }
};

// 12345674
// 4 5 5 7 6 4 7 
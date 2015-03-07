class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* ans = head;
        ListNode* temp = head;
        ListNode* temp2;
        while(temp)
        {
            temp2 = temp->next;
            while(temp2 && temp->val == temp2->val)
            {
                temp2= temp2->next;
            }
            temp->next = temp2;
            temp = temp->next;
        }
        return ans;
    }
};
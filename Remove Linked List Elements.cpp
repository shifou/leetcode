/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dum = new ListNode(-val);
        dum->next=head;
        ListNode* pre = dum,*cur=head;
        while(cur)
        {
            if(cur->val==val)
            {
                pre->next=cur->next;
            }
            else
            {
                pre=cur;
            }
            cur=cur->next;
        }
        return dum->next;
    }
};
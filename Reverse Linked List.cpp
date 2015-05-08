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
    ListNode* reverseList(ListNode* head) {
        ListNode * cur = new ListNode(0);
        ListNode * it = head;
        while(it)
        {
            ListNode * h1 = cur->next;
            cur->next = it;
            ListNode *h2=it->next;
            it->next = h1; 
            it=h2;
        }
        return cur->next;
    }
};
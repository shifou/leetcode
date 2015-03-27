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
    ListNode *sortList(ListNode *head) {
        if(head==0|| head->next==0)
           return head;
        int len=0;
        ListNode* hold = head;
        while(hold) {len++;hold=hold->next;}
        ListNode * fakehead = new ListNode(-1);
        fakehead->next=head;
        for(int seg=1;seg<len;seg*=2)
        {
            ListNode * c1 = fakehead->next,*c2=fakehead->next,*pre = fakehead;
            int time = len/(2*seg);
            if(len%(2*seg)!=0)
                time++;
            for(int i=0;i<time;i++)
            {
                int ct1=0,ct2=0;
                for(int j=0;c2&&j<seg;j++) c2=c2->next;
                while(c1&&c2 &&ct1<seg&&ct2<seg)
                {
                    if(c1->val<=c2->val)
                    {
                        pre->next = c1;
                        pre = c1;
                        c1=c1->next;
                        ct1++;
                    }
                    else
                    {
                        pre->next = c2;
                        pre=c2;
                        c2=c2->next;
                        ct2++;
                    }
                }
                while(c1&&ct1<seg)
                {
                    pre->next=c1;
                    pre=c1;
                    c1=c1->next;
                    ct1++;
                }
                while(c2&&ct2<seg)
                {
                    pre->next=c2;
                    pre=c2;
                    c2=c2->next;
                    ct2++;
                }
                pre->next=0;
                c1=c2;
            }
        }
        hold = fakehead->next;
        delete fakehead;
        return hold;
    }
};
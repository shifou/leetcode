class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode a(0);
        int c=0;
        ListNode *h1=l1,*h2=l2,*cur=&a, *ans=&a;
       // ans=ans->next;
        while(h1||h2)
        {
            if(!h1)
            {
                ans->next=h2;
                do
                {
                    h2->val=h2->val+c;
                    c=h2->val/10;
                    h2->val=(h2->val)%10;
                    if(h2->next)
                    h2=h2->next;
                    else break;
                }while(h2&&c>0);
                if(h2->next==NULL && c)
                {
                    ListNode* fk = new ListNode(c);
                    c=0;
                    h2->next=fk;
                }
                break;
            }
            if(!h2)
            {
                ans->next=h1;
                do
                {
                    h1->val=h1->val+c;
                    c=h1->val/10;
                    h1->val=(h1->val)%10;
                    if(h1->next)
                    h1=h1->next;
                    else break;
                }while(h1&&c>0);
                if(h1->next==NULL && c)
                {
                    ListNode* fk = new ListNode(c);
                    c=0;
                    h1->next=fk;
                }
                break;
            }
            ans->next=h1;
            h1->val=h1->val+h2->val+c;
            c=(h1->val)/10;
            h1->val=(h1->val)%10;
            h1=h1->next;
            h2=h2->next;
            ans=ans->next;
        }
        if(c)
        {
            ListNode * fk= new ListNode(c);
            ans->next=fk;
        }
        return cur->next;
    }
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode * h1 = l1;
        ListNode * h2 = l2;
        ListNode * root=NULL;
        ListNode * temp;
        if(h1==NULL)
            return h2;
        if(h2==NULL)
            return h1;
        while(h1||h2)
        {
             if(!h2)
             {
                temp->next = h1;
                break;
             }
            if(!h1)
            {
                temp->next = h2;
                break;
            }
            if(h1->val<h2->val)
            {
                if(root==NULL)
                {
                    root = h1;
                    temp=root;
                    h1=h1->next;
                    continue;
                }
                else
                    temp->next = h1;
                h1=h1->next;
            }
            else
            {
                 if(root==NULL)
                {
                    root = h2;
                    temp=root;
                    h2=h2->next;
                    continue;
                }
                else
                    temp->next = h2;
                h2=h2->next;
            }
            temp=temp->next;
        }
       
        return root;
    }
};
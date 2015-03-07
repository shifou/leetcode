class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headB==0||headA==0)
           return 0;
        int len1=0,len2=0;
        ListNode* a=headA,*b=headB;
        while(a)
        {
            a=a->next;
            len1++;
        }
        while(b)
        {
            b=b->next;
            len2++;
        }
        int dis=abs(len1-len2);
        a=headA,b=headB;
        if(len1>len2)
        {
            for(int i=1;i<=dis;i++)
                a=a->next;
        
        }
        else if(len1<len2)
        {
             for(int i=1;i<=dis;i++)
                b=b->next;
        }
        while(a)
        {
            if(a==b)
               return a;
            a=a->next;
            b=b->next;
        }
        return 0;
    }
};
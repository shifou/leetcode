class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==0)
           return 0;
        RandomListNode *ans=0;
        RandomListNode *cur=head;
        RandomListNode *ncur,*hold;
        // A  B  c
        // A' B' c'
        while(cur)
        {
            if(ans==0)
            {
                ans =new RandomListNode(cur->label);
                ncur=ans;
            }
            else
            {
                ncur=new RandomListNode(cur->label);
            }
            hold = cur->next;
            cur->next=ncur;
            ncur->next=hold;
            cur=hold;
            
        }
        cur=head;
        hold=ans;
        RandomListNode* tmp;
        
        while(cur)
        {
            cur->next->random =(cur->random)?cur->random->next:0;
            cur=cur->next->next;
        }
        cur=head;
        while(cur)
        {
            tmp=cur->next->next;
            hold->next= tmp?tmp->next:0;
            hold=hold->next;
            cur=cur->next=tmp;
        }
        return ans;
    }
};
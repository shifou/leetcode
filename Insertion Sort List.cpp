class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head){return NULL;}
        ListNode *p=new ListNode(0);
        p->next = head;
        head = p;
        ListNode *q;
         
        while (p->next!=NULL){
            q = head;
            bool flag = false;
            while (q!=p){
                if (q->next->val>p->next->val){
                    ListNode* tmp1=p->next;
                    p->next =p->next->next;
                    tmp1->next = q->next;
                    q->next = tmp1;
                    flag =true;
                    break;
                }else{
                    q=q->next;    
                }
            }
            if (!flag){
                p=p->next;
            }
        }
        return head->next;
    }
};
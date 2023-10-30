class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head;
        while(q && q->next)
        {
            p=p->next;
            q=q->next->next;
        }
        return p;
    }
};
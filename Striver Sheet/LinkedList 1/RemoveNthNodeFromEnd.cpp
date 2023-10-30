/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int count = 0;
        if(head == NULL || head->next == NULL)
            return NULL;
        while(temp2->next != NULL)
        {
            if(count < n)
            {
                count++;
                temp2 = temp2->next;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        if(count != n)
            return head->next;
        temp1->next = temp1->next->next;
        return head;
    }
};
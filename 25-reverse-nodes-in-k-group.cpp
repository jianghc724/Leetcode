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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        ListNode* s = NULL;
        ListNode* pre_p = head;
        ListNode* pre_pre_p = NULL;
        while (true)
        {
            for (int i = 0; i < k; i++)
            {
                if (p == NULL)
                {
                    return head;
                }
                q = p;
                p = p->next;
            } 
            if (pre_pre_p != NULL)
            {
            	pre_pre_p->next = q;
            }
            r = q->next;
            p = pre_p;
            if (pre_p == head)
            {
                head = q;
            }
            q = p->next;
            while (q != r)
            {
                s = q->next;
                q->next = p;
                p = q;
                q = s;
            }
            pre_p->next = r;
            pre_pre_p = pre_p;
            pre_p = r;
            p = r;
        }
        
    }
};

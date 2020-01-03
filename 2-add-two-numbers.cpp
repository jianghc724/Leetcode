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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode* c = new ListNode(((a->val + b->val) % 10));
        ListNode* res = c;
        int k = (a->val + b->val) / 10;
        a = a->next;
        b = b->next;
        
        while ((a != NULL) && (b != NULL)) {
            ListNode* p = new ListNode(((a->val + b->val + k) % 10));
            k = (a->val + b->val + k) / 10;
            c->next = p;
            c = c->next;
            a = a->next;
            b = b->next;
        }
        ListNode* d = NULL;
        if (a == NULL) {
            d = b;
        }
        if (b == NULL) {
            d = a;
        }
        while (d != NULL) {
            ListNode* p = new ListNode(((d->val + k) % 10));
            k = (d->val + k) / 10;
            c->next = p;
            c = c->next;
            d = d->next;
        }
        if (k != 0) {
            ListNode* p = new ListNode(k);
            c->next = p;
        }
        return res;
    }
};

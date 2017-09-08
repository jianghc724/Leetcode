/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MyTreeNode {
public:
    int val;
    int index;
    MyTreeNode* left;
    MyTreeNode* right;
    MyTreeNode* parent;
    MyTreeNode* next;
    
public:
    MyTreeNode() : val(0), index(-1), left(NULL), right(NULL), parent(NULL), next(NULL){}
    ~MyTreeNode(){}
};

class MyTree {
public:
    MyTreeNode* stat_start;
    MyTreeNode* root;
    
public:
    MyTree() : stat_start(NULL), root(NULL){}
    ~MyTree(){
        //delete
    }
    MyTreeNode* initialize(vector<ListNode*>& lists){
        int len = lists.size();
        MyTreeNode *p = NULL; 
        MyTreeNode *q = NULL;
        MyTreeNode *r = NULL; 
        MyTreeNode *s = NULL;
        MyTreeNode *start = NULL;
        for (int i = 0; i < len; i++){
            p = new MyTreeNode;
            if (p == NULL)
            {
                return NULL;
            }
            if (lists[i] != NULL)
            {
                p->val = lists[i]->val;
                p->index = i;
            }
            else
            {
                p->val = 0;
                p->index = -1;
            }
            p->left = NULL;
            p->right = NULL;
            p->parent = NULL;
            p->next = NULL;
            if (q != NULL)
            {
                q->next = p;
            }
            if (i == 0)
            {
                start = p;
                stat_start = p;
            }
            q = p;
        }
        int size = 0;
        p = start;
        start = NULL;
        while (true)
        {
            if (p == NULL)
            {
                if (size <= 1)
                {
                    root = start;
                    return root;
                }
                else
                {
                    p = start;
                    start = NULL;
                    s = NULL;
                    size = 0;
                }
            }
            else
            {
                q = p->next;
                if (q == NULL)
                {
                    r = new MyTreeNode;
                    if (r == NULL)
                    {
                        return NULL;
                    }
                    r->val = p->val;
                    r->index = p->index;
                    r->left = p;
                    r->right = NULL;
                    r->parent = NULL;
                    r->next = NULL;
                    p->parent = r;
                    if (s != NULL)
                    {
                        s->next = r;
                    }
                    if (start == NULL)
                    {
                        start = r;
                    }
                    size++;
                    p = NULL;
                }
                else
                {
                    int _p = p->val;
                    int _q = q->val;
                    r = new MyTreeNode;
                    if (r == NULL)
                    {
                        return NULL;
                    }
                    if (_p <= _q)
                    {
                        r->val = _p;
                        r->index = p->index;
                    }
                    else
                    {
                        r->val = _q;
                        r->index = q->index;
                    }
                    r->left = p;
                    r->right = q;
                    r->parent = NULL;
                    r->next = NULL;
                    p->parent = r;
                    q->parent = r;
                    if (s != NULL)
                    {
                        s->next = r;
                    }
                    if (start == NULL)
                    {
                        start = r;
                    }
                    s = r;
                    size++;
                    p = q->next;
                }
            }
        }
    }
    
    MyTreeNode* modify(int index, vector<ListNode*>& lists){
        MyTreeNode* p = stat_start;
        MyTreeNode* q = NULL;
        MyTreeNode* r = NULL;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                return NULL;
            }
        }
        ListNode* next_first = lists[index]->next;
        if (next_first == NULL)
        {
            p->val = 0;
            p->index = -1;
        }
        else
        {
            p->val = next_first->val;
        }
        lists[index] = next_first;
        r = p;
        while (r->parent != NULL)
        {
            r = r->parent;
            p = r->left;
            q = r->right;
            if (q == NULL)
            {
                r->val = p->val;
                r->index = p->index;
            }
            else
            {
                if (p->index == -1 && q->index == -1)
                {
                    r->val = 0;
                    r->index = -1;
                }
                else if (p->index == -1)
                {
                    r->val = q->val;
                    r->index = q->index;
                }
                else if (q->index == -1)
                {
                    r->val = p->val;
                    r->index = p->index;
                }
                else
                {
                    int _p = p->val;
                    int _q = q->val;
                    if (_p <= _q)
                    {
                        r->val = _p;
                        r->index = p->index;
                    }
                    else
                    {
                        r->val = _q;
                        r->index = q->index;
                    }
                }
            }
        }
        return r;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        MyTree t;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] == NULL)
            {
				lists.erase(lists.begin() + i);
				i--;
            }
        }
        MyTreeNode* root = t.initialize(lists);
        if (root == NULL)
        {
            return NULL;
        }
        ListNode* res = NULL;
        ListNode* pre = NULL;
        ListNode* cur = NULL;
        while (true)
        {
            int index = root->index;
            if (index == -1)
            {
                return res;
            }
            cur = lists[index];
            if (res == NULL)
            {
                res = cur;
            }
            if (pre != NULL)
            {
                pre->next = cur;
            }
            pre = cur;
            t.modify(index, lists);
            cur->next = NULL;
        }
    }
};

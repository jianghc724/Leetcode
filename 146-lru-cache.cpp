class CacheNode {
private:    
    int key;
    int value;
    CacheNode *next;

public:
    CacheNode(int k, int v){key = k; value = v; next = NULL;}
    ~CacheNode(){}
    int getKey(){return key;}
    int getValue(){return value;}
    CacheNode* getNext(){return next;}
    void setKey(int k){key = k;}
    void setValue(int v){value = v;}
    void setNext(CacheNode *n){next = n;}
};

class LRUCache {
private:
    CacheNode *cacheHead;
    CacheNode *cacheTail;
    int size;
    int capacity;
    
public:
    LRUCache(int c) {
        if (c <= 0)
        {
            capacity = 0;
        }
        else
        {
            capacity = c;
        }
        size = 0;
        cacheHead = NULL;
        cacheTail = NULL;
    }
    
    int get(int key) {
        if (find(key))
        {
            return cacheTail->getValue();
        }
        else
        {
            return -1;
        }
    }
    
    bool find(int key) {
        if (size == 0)
        {
            return false;
        }
        if (cacheTail->getKey() == key)
        {
            return true;
        }
        if (size == 1)
        {
            return false;
        }
        if (cacheHead->getKey() == key)
        {
            CacheNode *p = cacheHead->getNext();
            cacheHead->setNext(NULL);
            cacheTail->setNext(cacheHead);
            cacheTail = cacheHead;
            cacheHead = p;
            return true;
        }
        if (size == 2)
        {
            return false;
        }
        CacheNode *p = cacheHead;
        CacheNode *q = cacheHead->getNext();
        CacheNode *r = cacheHead->getNext()->getNext();
        while (r != NULL)
        {
            if (q->getKey() != key)
            {
                p = q;
                q = r;
                r = r->getNext();
            }
            else
            {
                p->setNext(r);
                q->setNext(NULL);
                cacheTail->setNext(q);
                cacheTail = q;
                return true;
            }
        }
        return false;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
        {
            return;
        }
        if (find(key))
        {
            cacheTail->setValue(value);
            return;
        }
        if (size < capacity)
        {
            CacheNode* p = new CacheNode(key, value);
            if (p)
            {
                size++;
                if (size == 1)
                {
                    cacheHead = p;
                    cacheTail = p;
                    return;
                }
                cacheTail->setNext(p);
                cacheTail = p;
            }
            return;
        }
        cacheHead->setKey(key);
        cacheHead->setValue(value);
        if (capacity == 1)
        {
            return;
        }
        CacheNode *p = cacheHead->getNext();
        cacheHead->setNext(NULL);
        cacheTail->setNext(cacheHead);
        cacheTail = cacheHead;
        cacheHead = p;    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

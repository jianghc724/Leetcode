class Solution {
public:
    int upper;
    
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        if (n < 1)
        {
            return res;
        }
        upper = n;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur = calNext(cur);
            res.push_back(cur);
        }
        return res;
    }
    
    int calNext(int cur)
    {
        if (cur == 0)
        {
            return 1;
        }
        
        if (cur * 10 <= upper)
        {
            return cur * 10;
        }
        
        if (cur % 10 == 9)
        {
            while (cur % 10 == 9)
            {
                cur /= 10;
            }
            return cur + 1;
        }
        
        if (cur + 1 > upper)
        {
            cur = cur / 10;
            while (cur % 10 == 9)
            {
                cur /= 10;
            }
            return cur + 1;
        }
        
        return cur + 1;
    }
};

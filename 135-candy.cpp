class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0)
        {
            return 0;
        }
        int res = 1;
        int pre_n = 0;
        int c_pre_n = 1;
        int pre = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                pre++;
                res = res + pre;
                pre_n = i;
                c_pre_n = pre;
            }
            else if (ratings[i] == ratings[i - 1])
            {
                pre = 1;
                res = res + pre;
                pre_n = i;
                c_pre_n = 1;
            }
            else
            {
                if (pre == 1)
                {
                    if (i - pre_n <= c_pre_n - 1)
                    {
                        res = res + (i - pre_n);
                    }
                    else
                    {
                        res = res + (i - pre_n + 1);
                    }
                }
                else
                {
                    pre = 1;
                    res = res + 1;
                }
            }
        }
        
        return res;
    }
};

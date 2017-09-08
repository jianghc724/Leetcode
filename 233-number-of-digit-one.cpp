class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        while (n >= 10)
        {
            int s = 0;
            int r = 1;
            int m = n / 10;
            while (m > 0)
            {
                s++;
                m /= 10;
                r *= 10;
            }
            int t = n / r;
            res = res + s * t * (r / 10);
            if (t >= 2)
            {
                res = res + r;
            }
            else
            {
                res = res + n % r + 1;
            }
            n = n % r;
        }
        
        if (n >= 1)
        {
            res = res + 1;
        }
        
        return res;
    }
};

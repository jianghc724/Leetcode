class Solution {
public:    
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1;
        }
        if (x == 0)
        {
            return 0;
        }
        
        if (n < 0)
        {
            return (1 / cal(x, -n));
        }
        else
        {
            return cal(x, n);
        }
    }
    
    double cal(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return x;
        }
        
        double left = cal(x, n / 2);
        if (n % 2 == 0)
        {
            return left * left;
        }
        else
        {
            return left * left * x;
        }
    }
};

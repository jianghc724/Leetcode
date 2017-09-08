class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            flag = false;
            x = -x;
        }
        int result = 0;
        int pre_result = 0;
        while (x != 0)
        {
            if (result > INT_MAX / 10)
            {
                return 0;
            }
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if (flag)
        {
            return result;
        }
        else
        {
            return -result;
        }
    }
};

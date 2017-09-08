class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int result = 0;
        bool flag = true;
        int t = 0;
        while (true)
        {
            if (str[t] != ' ')
            {
                break;
            }
            t++;
        }
        if (str[t] == '-')
        {
            flag = false;
        }
        else if (str[t] == '+')
        {
            flag = true;
        }
        else if ((str[t] >= '0') && (str[t] <= '9'))
        {
            result = (int)(str[t] - '0');
        }
        else
        {
            return 0;
        }
        for (int i = t + 1; i < len; i++)
        {
            if ((str[i] < '0') or (str[i] > '9'))
            {
                if (flag)
                {
                    return result;
                }
                else
                {
                    return -result;
                }
            }
            if (result > INT_MAX / 10)
            {
                if (flag)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
            result = result * 10 + (int)(str[i] - '0');
            if (result < 0)
            {
                if (flag)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
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

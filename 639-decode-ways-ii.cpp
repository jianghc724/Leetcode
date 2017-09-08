class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0 || s == "0")
        {
            return 0;
        }
        char prev = '\0';
        vector<long long> res(len + 2, 1);
        for (int i = 0; i < len; i++)
        {
            char cur = s[i];
            if (prev == '*')
            {
                if (cur == '*')
                {
                    res[i + 2] = (res[i + 1] * 9) + (res[i] * 15);
                }
                else if (cur == '0')
                {
                    res[i + 2] = res[i] * 2;
                }
                else if (cur >= '1' && cur <= '6')
                {
                    res[i + 2] = res[i + 1] + (res[i] * 2);
                }
                else
                {
                    res[i + 2] = res[i + 1] + res[i];
                }
            }
            else if (prev == '1')
            {
                if (cur == '*')
                {
                    res[i + 2] = (res[i + 1] * 9) + (res[i] * 9);
                }
                else if (cur == '0')
                {
                    res[i + 2] = res[i];
                }
                else
                {
                    res[i + 2] = res[i + 1] + res[i];
                }
            }
            else if (prev == '2')
            {
                if (cur == '*')
                {
                    res[i + 2] = (res[i + 1] * 9) + (res[i] * 6);
                }
                else if (cur == '0')
                {
                    res[i + 2] = res[i];
                }
                else if (cur >= '1' && cur <= '6')
                {
                    res[i + 2] = res[i + 1] + res[i];
                }
                else
                {
                    res[i + 2] = res[i + 1];
                }
            }
            else
            {
                if (cur == '*')
                {
                    res[i + 2] = res[i + 1] * 9;
                }
                else if (cur == '0')
                {
                    if (prev != '1' && prev != '2')
                    {
                        return 0;
                    }
                    res[i + 2] = res[i];
                }
                else
                {
                    res[i + 2] = res[i + 1];
                }
            }
            prev = cur;
            res[i + 2] %= (1000000007);
        }
        return res[len + 1];
    }
};

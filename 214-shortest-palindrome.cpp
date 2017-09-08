class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if (len <= 1)
        {
            return s;
        }
        char c = s[0];
        int cur = len - 1;
        string res_pre;
        for (; cur >= 0; cur--)
        {
            if (s[cur] == c)
            {
                bool flag = true;
                for (int i = 1; i <= cur / 2; i++)
                {
                    if (s[i] != s[cur - i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
            res_pre.push_back(s[cur]);
        }
        return res_pre + s;
    }
};

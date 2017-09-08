class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> left;
        int len = s.length();
        int pre_start = -1;
        int pre_end = -1;
        int res = 0;
        bool isSet = false;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                left.push_back(i);
            }
            else if (s[i] == ')')
            {
                int n = left.size();
                if (n == 0)
                {
                    if (isSet)
                    {
                        if (pre_end - pre_start + 1 > res)
                        {
                            res = pre_end - pre_start + 1;
                        }
                    }    
                    pre_start = i;
                    pre_end = i;
                    isSet = false;
                }
                else if (n == 1)
                {
                    pre_end = i;
                    if (!isSet)
                    {
                        isSet = true;
                        pre_start++;
                    }
                    left.pop_back();
                    if (pre_end - pre_start + 1 > res)
                    {
                        res = pre_end - pre_start + 1;
                    }
                }
                else
                {
                    left.pop_back();
                    int _s = left.size();
                    if (i - left[_s - 1] > res)
                    {
                        res = i - left[_s - 1];
                    }
                }
            }
        }
        return res;
    }
};

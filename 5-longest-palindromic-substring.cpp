class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string res;
        if (len == 0)
        {
            return res;
        }
        res.push_back(s[0]);
        int max_len = 1;
        for (int i = 0; i < len; i++)
        {
            int j = i + 1;
            int k = i;
            while (k >= 0 && j <= len - 1 && s[k] == s[j])
            {
                k--;
                j++;
            }
            if (max_len < (j - 1) - (k + 1) + 1)
            {
                max_len = (j - 1) - (k + 1) + 1;
                res = s.substr(k + 1, max_len);
            }
            
            j = i + 2;
            k = i;
            while (k >= 0 && j <= len - 1 && s[k] == s[j])
            {
                k--;
                j++;
            }
            if (max_len < (j - 1) - (k + 1) + 1)
            {
                max_len = (j - 1) - (k + 1) + 1;
                res = s.substr(k + 1, max_len);
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0)
        {
            return res;
        }
        int len = INT_MAX;
        for (auto s : strs)
        {
            if (s.size() < len)
            {
                len = s.size();
            }
        }
        
        int i = 0;
        while (i < len)
        {
            char c = strs[0][i];
            bool flag = true;
            for (auto s : strs)
            {
                if (s[i] != c)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res.push_back(c);
            }
            else
            {
                break;
            }
            i++;
        }
        
        return res;
    }
};

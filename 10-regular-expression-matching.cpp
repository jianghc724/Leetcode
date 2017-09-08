class Solution {
public:
    bool isMatch(string s, string p) {
        int s_i = 0;
        int p_i = 0;
        int s_len = s.length();
        int p_len = p.length();
        if (s_len == 0 && p_len == 0)
        {
            return true;
        }
        bool flag = true;
        while (s_i < s_len && p_i < p_len)
        {
            if (!flag && p[p_i] != '*')
            {
                return false;
            }
            
            if (!flag && p[p_i] == '*')
            {
                p_i++;
                flag = true;
                continue;
            }
            
            if (s[s_i] == p[p_i])
            {
                if (p_i == p_len - 1 && s_i == s_len - 1)
                {
                    return true;
                }
                if (p[p_i + 1] != '*')
                {
                    s_i++;
                }
                p_i++;
                flag = true;
                continue;
            }
            
            if (p[p_i] == '.')
            {
                if (p_i == p_len - 1 && s_i == s_len - 1)
                {
                    return true;
                }
                if (p[p_i + 1] != '*')
                {
                    s_i++;
                }
                p_i++;
                flag = true;
                continue;
            }
            
            if (p[p_i] == '*')
            {
                if (p_i == 0)
                {
                    return false;
                }
                char temp = p[p_i - 1];
                while (p[p_i] == '*')
                {
                    p_i++;
                }
                string next_p = p.substr(p_i);
                if (temp == '.')
                {
                    if (p_i == p_len)
                    {
                        return true;
                    }
                    while (s_i <= s_len)
                    {
                        bool val = isMatch(s.substr(s_i), next_p);
                        if (val)
                        {
                            return true;
                        }
                        s_i++;
                    }
                    return false;
                }
                while (s_i < s_len)
                {
                    bool val = isMatch(s.substr(s_i), next_p);
                    if (val)
                    {
                        return true;
                    }
                    s_i++;
                    if (s[s_i] != temp)
                    {
                        break;
                    }
                }
                continue;
            }
            
            flag = false;
            p_i++;
        }
        
        if (s_i == s_len && p_i == p_len)
        {
            return true;
        }
        
        if (s_i == s_len)
        {
            bool _flag = true;
            while (p_i < p_len)
            {
                if (!_flag && p[p_i] != '*')
                {
                    return false;
                }
                
                if (p[p_i] == '*')
                {
                    _flag = true;
                    p_i++;
                    continue;
                }
                
                _flag = false;
                p_i++;
            }
            
            if (_flag)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if (p_i == p_len)
        {
            return false;
        }
    }
};

class Solution {
public:
    vector<string> _str;
    
    int findLUSlength(vector<string>& strs) {
        int len = strs.size();
        if (len == 0)
        {
            return -1;
        }
        
        if (len == 1)
        {
            return strs[0].size();
        }
        
        sort(strs.begin(), strs.end(), [](string a, string b) -> bool {if (a.size() != b.size()) return a.size() > b.size(); int i = 0; while (i < a.size()){if (a[i] != b[i]) return a[i] < b[i]; i++;} return false;});
        
        
        int i = 0;
        int max_length = strs[0].size();
        _str.push_back(strs[0]);
        while (strs[i].size() == max_length)
        {
            if (strs[i] != strs[i + 1])
            {
                return max_length;
            }
            while (strs[i] == strs[i + 1])
            {
                i++;
            }
            i++;
        }
        
        for (int j = i; j < len; j++)
        {
            if (j != len - 1)
            {
                if (strs[j] == strs[j + 1])
                {
                    while (j != len - 1 && strs[j] == strs[j + 1])
                    {
                        j++;
                    }
                    _str.push_back(strs[j]);
                    continue;
                }
            }
            if (find(strs[j]))
            {
                return strs[j].size();
            }
        }
        
        return -1;
    }
    
    bool find(string ss)
    {
        for (auto s : _str)
        {
            int i = 0;
            int j = 0;
            while (i < s.size() && j < ss.size())
            {
                if (s[i] == ss[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            if (j == ss.size())
            {
                return false;
            }
        }
        
        return true;
    }
};

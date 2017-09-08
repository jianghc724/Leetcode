class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        vector<set<pair<int, int>>> dp;
        set<pair<int, int>> _cur;
        if (s1[0] == s3[0])
        {
            _cur.insert(make_pair(1, 0));
        }
        if (s2[0] == s3[0])
        {
            _cur.insert(make_pair(0, 1));
        }
        dp.push_back(_cur);
        int len = s3.size();
        for (int i = 1; i < len; i++)
        {
            if (dp[i - 1].empty())
            {
                return false;
            }
            set<pair<int, int>> cur;
            set<pair<int, int>> pre = dp[i - 1];
            
            for (auto p : pre)
            {
                if (s1[p.first] == s3[i])
                {
                    cur.insert(make_pair(p.first + 1, p.second));
                }
                
                if (s2[p.second] == s3[i])
                {
                    cur.insert(make_pair(p.first, p.second + 1));
                }
            }
            
            dp.push_back(cur);
        }
        
        if (!dp[len - 1].empty())
        {
            return true;
        }
        return false;
    }
};

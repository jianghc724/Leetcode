class Solution {
public:
    
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        if (len == 0)
        {
            return false;
        }
        if (len == 1)
        {
            return true;
        }
        if (stones[1] != 1)
        {
            return false;
        }
        vector<pair<int, int>> last;
        last.push_back(make_pair(1, 1));
        for (int i = 2; i < len - 1; i++)
        {
            int _len = last.size();
            if (_len == 0)
            {
                return false;
            }
            int j = 0;
            int pre = -1;
            while (j < _len)
            {
                if (last[j].first + last[j].second + 1 < stones[i])
                {
                    last.erase(last.begin() + j);
                    _len--;
                    continue;
                }
                
                if (last[j].first + last[j].second - 1 <= stones[i] && last[j].first + last[j].second + 1 >= stones[i])
                {
                    if (pre != last[j].first)
                    {
                        last.push_back(make_pair(stones[i], stones[i] - last[j].first));
                        pre = last[j].first;
                    }
                }
                j++;
            }
        }
        
        int _len = last.size();
        if (_len == 0)
        {
            return false;
        }
        for (int j = 0; j < _len; j++)
        {
            if (last[j].first + last[j].second - 1 <= stones[len - 1] && last[j].first + last[j].second + 1 >= stones[len - 1])
            {
                return true;
            }
        }
        
        return false;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> t(26, 0);
        for (auto c : tasks) {
            t[c - 'A']++;
        }
        
        int m = 0;
        
        for (auto k : t) {
            if (k > m) {
                m = k;
            }
        }
        
        int res = (m - 1) * (n + 1);
        
        for (auto k : t) {
            if (k == m) {
                res++;
            }
        }
        
        if (res < tasks.size()) {
            res = tasks.size();
        }
        
        return res;
    }
};

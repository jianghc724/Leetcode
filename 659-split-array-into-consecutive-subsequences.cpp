class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<pair<int, int>> se;
        int s = 0;
        for (auto n : nums) {
            int i = s - 1;
            bool flag = false;
            for (; i >= 0; i--) {
                if (se[i].first == n - 1) {
                    se[i].first++;
                    se[i].second++;
					flag = true;
					break;
                }
            }
            if (!flag) {
                se.push_back(make_pair(n, 1));
                s++;
            }
            for (i = 0; i < s; i++) {
                if (se[i].first <= n - 2) {
                    if (se[i].second <= 2) {
                        return false;
                    } else {
                        se.erase(se.begin() + i);
                        i--;
                        s--;
                    }
                } else {
                    break;
                }
            }
        }
        
        for (int i = 0; i < s; i++) {
            if (se[i].second <= 2) {
                return false;
            }
        }
        
        return true;
    }
};

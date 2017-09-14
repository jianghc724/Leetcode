class Solution {
public:
    int s;
    int index;
    vector<vector<int>> res;
    vector<pair<int, int>> n;
    unordered_map<int, int> m;
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        s = nums.size();
        index = 0;
        for (auto x : nums) {
            if (m.find(x) != m.end()) {
                n[m[x]].second++;
            } else {
                m[x] = index;
                index++;
                n.push_back(make_pair(x, 1));
            }
        }
        vector<int> r;
        cal(r);
        return res;
    }
    
    void cal(vector<int> r) {
        if (r.size() == s) {
            res.push_back(r);
        } else {
            for (int i = 0; i < index; i++) {
                if (n[i].second != 0) {
                    n[i].second--;
                    r.push_back(n[i].first);
                    cal(r);
                    r.pop_back();
                    n[i].second++;
                }
            }
        }
    }
};

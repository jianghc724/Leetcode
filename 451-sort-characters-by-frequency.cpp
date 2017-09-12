class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        vector<pair<char, int>> f;
        int index = 0;
        for (auto c : s) {
            if (m.find(c) != m.end()) {
                f[m[c]].second++;
            } else {
                m[c] = index;
                f.push_back(make_pair(c, 1));
                index++;
            }
        }
        sort(f.begin(), f.end(), [](pair<char, int> a, pair<char, int> b) -> bool{if (a.second != b.second) return a.second > b.second; return a.first < b.first;});
        string res;
        for (auto p : f) {
            for (int i = 0; i < p.second; i++) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};

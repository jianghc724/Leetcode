class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<pair<int, int>> n;
        int index = 0;
        for (auto x : nums) {
            if (m.find(x) != m.end()) {
                n[m[x]].second++;
            } else {
                m[x] = index;
                n.push_back(make_pair(x, 1));
                index++;
            }
        }
        sort(n.begin(), n.end(), [](pair<int, int> a, pair<int, int> b) -> bool {if (a.second != b.second) return a.second > b.second; return a.first < b.first;});
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(n[i].first);
        }
        return res;
    }
};

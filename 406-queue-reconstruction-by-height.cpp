class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) -> bool {if (a.first != b.first) return a.first < b.first; return a.second > b.second;});
        int s = people.size();
        vector<pair<int, int>> res(s, make_pair(0, 0));
        vector<int> cur;
        for (int i = 0; i < s; i++) {
            cur.push_back(i);
        }
        for (auto x : people) {
            res[cur[x.second]] = x;
            cur.erase(cur.begin() + x.second);
        }
        return res;
    }
};

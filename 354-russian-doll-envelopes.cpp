class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b) -> bool {if (a.first != b.first) return a.first < b.first; return a.second > b.second;});
        int s = 0;
        vector<int> tail(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = s;
            while (j != k) {
                int m = j + (k - j) / 2;
                if (tail[m] < envelopes[i].second) {
                    j = m + 1;
                } else {
                    k = m;
                }
            }
            tail[j] = envelopes[i].second;
            if (j == s) {
                s++;
            }
        }
        return s;
    }
};

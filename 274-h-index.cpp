class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = citations.size();
        vector<int> num(s + 1, 0);
        for (auto x : citations) {
            if (x >= s) {
                num[s]++;
            } else {
                num[x]++;
            }
        }
        int res = 0;
        for (int i = s; i >= 0; i--) {
            res += num[i];
            if (res >= i) {
                return i;
            }
        }
    }
};

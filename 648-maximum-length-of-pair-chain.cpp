class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)->bool{if (a[1] != b[1]) return a[1] < b[1]; return a[0] < b[0];});
        int res = 0;
        int pre = INT_MIN;
        for (auto p : pairs) {
            if (p[0] > pre) {
                res++;
                pre = p[1];
            }
        }
        return res;
    }
};

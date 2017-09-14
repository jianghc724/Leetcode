class Solution {
public:
    vector<vector<int>> res;
    vector<bool> isUsed;
    int k0, n0;
    
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k) {
            return res;
        }
        k0 = k;
        n0 = n;
        for (int i = 0; i < n; i++) {
            isUsed.push_back(false);
        }
        vector<int> r;
        cal(r, -1);
        return res;
    }
    
    void cal(vector<int> r, int pre) {
        if (r.size() == k0) {
            res.push_back(r);
        } else {
            if (r.size() + n0 - (pre + 1) < k0) {
                return;
            }
            for (int i = pre + 1; i < n0; i++) {
                if (!isUsed[i]) {
                    r.push_back(i + 1);
                    isUsed[i] = true;
                    cal(r, i);
                    isUsed[i] = false;
                    r.pop_back();
                }
            }
        }
    }
};

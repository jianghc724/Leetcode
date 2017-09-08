class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if (m == 0 && n == 0) {
            return true;
        } else if (n == 0) {
            return false;
        }
        
        if (m == 0) {
            int i = 0;
            while (i < n) {
                if (p[i] == '*') {
                    i++;
                } else {
                    return false;
                }
            }
            return true;
        }
        
        vector<vector<bool>> res(m + 1, vector<bool>(n + 1, false));
        res[0][0] = true;
        
        int temp = 0;
        while (p[temp] == '*') {
            res[0][temp + 1] = true;
            temp++;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j]) {
                    if (s[i] == p[j] || p[j] == '?' || p[j] == '*') {
                        res[i + 1][j + 1] = true;
                    }
                }
                
                if (res[i][j + 1] && p[j] == '*') {
                    res[i + 1][j + 1] = true;
                }
                
                if (res[i + 1][j] && p[j] == '*') {
                    res[i + 1][j + 1] = true;
                }
            }
        }
        
        return res[m][n];
    }
};

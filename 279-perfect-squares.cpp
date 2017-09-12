class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, 0);
        int next_sq = 2;
        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (next_sq * next_sq == i) {
                res[i] = 1;
                next_sq++;
            } else {
                int m = res[i - 1];
                for (int j = 2; j < next_sq; j++) {
                    if (m > res[i - j * j]) {
                        m = res[i - j * j];
                    }
                }
                res[i] = m + 1;
            }
        }
        return res[n];
    }
};

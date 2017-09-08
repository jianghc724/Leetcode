class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) {
            return 0;
        } else {
            int res = 0;
            while (n > 0) {
                res += n / 5;
                n /= 5;
            }
            return res;
        }
    }
};

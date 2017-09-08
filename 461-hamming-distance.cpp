class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int i = 0;
        int res = 0;
        while (n && i < 32) {
            if (n % 2) {
                res++;
            }
            n = n >> 1;
            i++;
        }
        return res;
    }
};

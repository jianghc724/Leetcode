class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else {
            int a = 1;
            int b = 1;
            for (int i = 2; i <= n; i++) {
                int temp = a;
                a = b;
                b = temp + a;
            }
            return b;
        }
    }
};

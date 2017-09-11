class Solution {
public:
    string convertToTitle(int n) {
        string sample = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int s = 26;
        int i = 1;
        while (n > s) {
            n -= s;
            i++;
            if (INT_MAX / 26 > s) {
                s *= 26;
            } else {
                break;
            }
        }
        string res;
        n--;
        while (i > 0) {
            i--;
            res.insert(res.begin(), sample[n % 26]);
            n /= 26;
        }
        return res;
    }
};

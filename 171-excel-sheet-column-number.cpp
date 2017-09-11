class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int res = 0;
        int n = 26;
        int i = len;
        while (i > 1) {
            i--;
            res += n;
            n *= 26;
        }
        int delta = 0;
        for (auto c : s) {
            delta = delta * 26 + (c - 'A');
        }
        
        res = res + delta + 1;
        return res;
    }
};

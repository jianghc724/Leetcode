class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int len = s.size();
        int i = 0;
        while (s[len - 1 - i] == ' ') {
            i++;
        }
        while (s[len - 1 - res - i] != ' ' && res + i < len) {
            res++;
        }
        return res;
    }
};

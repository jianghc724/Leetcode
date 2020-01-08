class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        string res = "";
        while (s[len - 1] == ' ') {
            len--;
            if (len == -1) {
                return res;
            }
        }
        int end = len;
        int start = len;
        bool flag = true;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                continue;
            }
            start = i + 1;
            while (s[i] == ' ') {
                i--;
                if (i == -1) {
                    flag = false;
                    break;
                }
            }
            res += s.substr(start, end - start);
            if (flag) {
                res += ' ';
            }
            end = i + 1;
        }
        if (flag) {
            res += s.substr(0, end);
        }
        return res;
    }
};

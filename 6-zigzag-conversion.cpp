class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int len = s.length();
        string res = "";
        for (int i = 0; i < numRows; i++) {
            int n = i;
            while (n < len) {
                res += s[n];
                if ((i != 0) and (i != numRows - 1)){
                    int m = n + (2 * (numRows - 1 - i));
                    if (m < len){
                        res += s[m];
                    }
                }
                n = n + 2 * (numRows - 1);
            }
        }
        return res;
    }
};

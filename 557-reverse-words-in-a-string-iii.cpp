class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int len = s.size();
        int i = 0;
        while (i < len) {
            if (s[i] == ' ') {
                end = i - 1;
                while (start < end) {
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;
                    end--;
                    start++;
                }
                start = i + 1;
                i++;
            } else {
                i++;
            }
        }
        
        end = len - 1;
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            end--;
            start++;
        }
        
        return s;
    }
};

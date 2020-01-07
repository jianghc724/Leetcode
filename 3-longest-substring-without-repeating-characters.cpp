class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int position[256];
        int maxLen = 0;
        int start = 0;
        int end = 0;
        int length = s.length();
        for (int i = 0; i < 256; i++) {
            position[i] = -1;
        }
        for (int i = 0; i < length; i++) {
            char c = s[i];
            if (position[c] != -1) {
                int len = end - start;
                if (len > maxLen) {
                    maxLen = len;
                }
                for (int j = start; j < position[c]; j++) {
                    position[s[j]] = -1;
                }
                start = position[c] + 1;
            }
            end++;
            position[c] = i;
        }
        int len = end - start;
        if (len > maxLen) {
            maxLen = len;
        }
        return maxLen;
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        if (len <= 1)
        {
            return s;
        }
        int last[26];
        for (int i = 0; i < 26; i++)
        {
            last[i] = len;
        }
        int start = 0;
        int end = 0;
        int cha = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (last[s[i]- 'a'] == len)
            {
                last[s[i] - 'a'] = i;
                end = i;
                cha++;
            }
        }
        int pos = 0;
        string res;
        while (cha > 0)
        {
            int cur = start;
			bool isSet = false;
            for (int i = start; i <= end; i++)
            {
                if (last[s[i] - 'a'] != len && (s[i] < s[cur] || !isSet))
                {
                    cur = i;
					isSet = true;
                }
            }
            res.push_back(s[cur]);
            last[s[cur] - 'a'] = len;
            int temp = 26;
            int cur_min = len;
            for (int i = 0; i < 26; i++)
            {
                if (last[i] < cur_min)
                {
                    cur_min = last[i];
                    temp = i;
                }
            }
            end = cur_min;
            start = cur + 1;
            cha--;
        }
        return res;
    }
};

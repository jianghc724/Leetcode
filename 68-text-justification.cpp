class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int sum = 0;
        int index = 0;
        vector<string> result;
        int start = 0;
        int end = 0;
        while (index < n)
        {
            int len = words[index].length();
            if (sum == 0)
            {
                start = index;
                end = index;
                sum = len;
                index++;
                continue;
            }
            if (sum + len + 1 <= maxWidth)
            {
                sum = sum + len + 1;
                end++;
                index++;
            }
            else
            {
                string res;
                int temp = 0;
                for (int i = start; i <= end; i++)
                {
                    temp += words[i].length();
                }
                int space = maxWidth - temp;
                int basic_space = 0;
                int extra_space = 0;
                if (end != start)
                {
                    basic_space = space / (end - start);
                }
                extra_space = space - basic_space * (end - start);
                for (int i = start; i < end; i++)
                {
                    res = res + words[i];
                    for (int j = 0; j < basic_space; j++)
                    {
                        res = res + ' ';
                    }
                    if (extra_space != 0)
                    {
                        res = res + ' ';
                        extra_space--;
                    }
                }
                res = res + words[end];
                for (int i = 0; i < extra_space; i++)
                {
                    res = res + ' ';
                }
                result.push_back(res);
                sum = 0;
            }
        }
        string res;
        int temp = 0;
        for (int i = start; i <= end; i++)
        {
            temp += words[i].length();
        }
        int space = maxWidth - temp;
        int extra_space = 0;
        extra_space = space - (end - start);
        for (int i = start; i < end; i++)
        {
            res = res + words[i] + ' ';
        }
        res = res + words[end];
        for (int i = 0; i < extra_space; i++)
        {
            res = res + ' ';
        }
        result.push_back(res);
        return result;
    }
};

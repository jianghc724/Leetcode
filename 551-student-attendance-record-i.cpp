class Solution {
public:
    bool checkRecord(string s) {
        int l = 0;
        bool a = false;
        for (auto c : s)
        {
            if (c == 'A')
            {
                if (a)
                {
                    return false;
                }
                a = true;
                l = 0;
            }
            else if (c == 'L')
            {
                l++;
                if (l == 3)
                {
                    return false;
                }
            }
            else
            {
                l = 0;
            }
        }
        return true;
    }
};

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() != b.size())
        {
            return max(a.size(), b.size());
        }
        if (a != b)
        {
            return a.size();
        }
        else
        {
            return -1;
        }
    }
};

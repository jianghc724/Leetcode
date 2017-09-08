class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string a, string b) -> bool {if (a.size() != b.size()) return a.size() > b.size(); int i = 0; while(i == a.size() || a[i] == b[i])i++; if (i == a.size()) return true; return a[i] < b[i];});
        int m = s.size();
        for (auto r : d) {
            int n = r.size();
            int i = 0;
            int j = 0;
            while (i < m && j < n) {
                if (s[i] == r[j]) {
                    j++;
                }
                i++;
            }
            
            if (j == n) {
                return r;
            }
        }
        return "";
    }
};

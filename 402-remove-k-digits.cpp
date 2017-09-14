class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }
        
        if (k == 0) {
            string res = num;
            int len = res.size();
            while (len > 0) {
                if (res[0] != '0') {
                    break;
                }
                res.erase(res.begin());
                len--;
            }

            if (len == 0) {
                return "0";
            }

            return res;
        }
        
        int len = num.size() - k;
        string res = num.substr(k, len);
        int i = k - 1;
        while (i >= 0) {
            if (num[i] == res[0]) {
                int s = 0;
                while (s < len - 1 && res[s] == res[s + 1]) {
                    s++;
                }
                if (s != len - 1 && res[s] < res[s + 1]) {
                    while (s < len - 1 && res[s] <= res[s + 1]) {
                        s++;
                    }
                    res.erase(res.begin() + s);
                    res.insert(res.begin(), num[i]);
                }
            } else if (num[i] < res[0]) {
                int s = 0;
                while (s < len - 1 && res[s] <= res[s + 1]) {
                    s++;
                }
                res.erase(res.begin() + s);
                res.insert(res.begin(), num[i]);
            }
            
            i--;
        }
        
        while (len > 0) {
            if (res[0] != '0') {
                break;
            }
            res.erase(res.begin());
            len--;
        }
        
        if (len == 0) {
            return "0";
        }
        
        return res;
    }
};

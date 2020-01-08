class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int>::iterator i;
        bool flag = true;
        for (i = nums.begin(); i < nums.end(); i++) {
            vector<int>::iterator j = i + 1;
            if (j == nums.end()) {
                break;
            }
            if (*i <= *j) {
                continue;
            } else if (flag == false) {
                return false;
            } else {
                flag = false;
                if (i == nums.begin()) {
                    continue;
                }
                vector<int>::iterator m = j + 1;
                if (m == nums.end()) {
                    break;
                }
                if (*j > *m) {
                    return false;
                }
                if (*i <= *m) {
                    continue;
                }
                vector<int>::iterator n = i - 1;
                if (*n > *j) {
                    return false;
                }
            }
        }
        return true;
    }
};

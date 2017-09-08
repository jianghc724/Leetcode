class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> diff;
        unordered_map<int, int> dif_map;
        int d = 0;
        int res = 0;
        dif_map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                d++;
            } else {
                d--;
            }
            
            if (dif_map.find(d) == dif_map.end()) {
                dif_map[d] = i;
            } else {
                if (res < i - dif_map[d]) {
                    res = i - dif_map[d];
                }
            }
        }
        return res;
    }
};

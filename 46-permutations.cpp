class Solution {
public:
    vector<vector<int>> res;
    vector<bool> isUsed;
    int len;
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        vector<int> r;
        for (int i = 0; i < len; i++) {
            isUsed.push_back(false);
        }
        cal(nums, r);
        return res;
    }
    
    void cal(vector<int>& nums, vector<int> r) {
        if (r.size() == len) {
            res.push_back(r);
            return;
        }
        
        for (int i = 0; i < len; i++) {
            if (!isUsed[i]) {
                r.push_back(nums[i]);
                isUsed[i] = true;
                cal(nums, r);
                isUsed[i] = false;
                r.pop_back();
            }
        }
    }
};

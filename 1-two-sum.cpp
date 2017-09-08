class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        if (len < 2)
        {
            return res;
        }
        vector<int> num_needed;
        int i = 0;
        for (auto x : nums)
        {
            int j = 0;
            for (auto y : num_needed)
            {
                if (x == y)
                {
                    res.push_back(j);
                    res.push_back(i);
                    return res;
                }
                j++;
            }
            num_needed.push_back(target - x);
            i++;
        }
        
    }
};

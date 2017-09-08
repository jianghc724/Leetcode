class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> f_res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++)
        {
            if (i != 0)
            {
                if (nums[i - 1] == nums[i])
                {
                    continue;
                }
            }
            int t = -nums[i];
            map<int, int> num_map;
            for (int j = i + 1; j < len; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                num_map.insert(make_pair(t-nums[j], j));
            }
            for (int j = i + 1; j < len; j++)
            {
                map<int, int>::iterator it = num_map.find(nums[j]);
                if (it != num_map.end() && it->second != j)
                {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(t-nums[j]);
                    res.push_back(nums[j]);
                    f_res.push_back(res);
                    num_map.erase(it);
                    if (num_map.find(t-nums[j]) != num_map.end()) num_map.erase(num_map.find(t-nums[j]));
                }
            }
            
        }
        return f_res;
    }
};

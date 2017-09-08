class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> f_res;
        sort(nums.begin(), nums.end());
        if (len == 0)
        {
            return f_res;
        }
        if (4 * nums[len - 1] < target)
        {
            return f_res;
        }
        for (int x = 0; x < len; x++)
        {
            if (x != 0)
            {
                if (nums[x - 1] == nums[x])
                {
                    continue;
                }
            }
            if (4 * nums[x] > target)
            {
                break;
            }
            if (3 * nums[len - 1] + nums[x] < target)
            {
                continue;
            }
            for (int i = x + 1; i < len; i++)
            {
                if (i != x + 1)
                {
                    if (nums[i - 1] == nums[i])
                    {
                        continue;
                    }
                }
                if (3 * nums[i] + nums[x] > target)
                {
                    break;
                }
                long long int t = target - nums[x] - nums[i];
                map<long long int, int> num_map;
                for (int j = i + 1; j < len; j++)
                {
                    if (j != i + 1 && nums[j] == nums[j - 1])
                    {
                        continue;
                    }
                    num_map.insert(make_pair(t - nums[j], j));
                }
                for (int j = i + 1; j < len; j++)
                {
                    map<long long int, int>::iterator it = num_map.find(nums[j]);
                    if (it != num_map.end() && it->second != j)
                    {
                        vector<int> res;
                        res.push_back(nums[x]);
                        res.push_back(nums[i]);
                        res.push_back(target - nums[i]- nums[x]- nums[j]);
                        res.push_back(nums[j]);
                        f_res.push_back(res);
                        num_map.erase(it);
                        map<long long int, int>::iterator _it = num_map.find(target - nums[i]- nums[x]- nums[j]);
                        if (_it != num_map.end()) num_map.erase(_it);
                    }
                }

            }
        }
        return f_res;
    }
};

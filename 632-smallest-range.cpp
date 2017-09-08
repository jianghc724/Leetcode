class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> cur;
        vector<int> v_res;
        int len = nums.size();
        if (len == 0)
        {
            return v_res;
        }
        if (len == 1)
        {
            v_res.push_back(nums[0][0]);
            v_res.push_back(nums[0][0]);
            return v_res;
        }
        for (int i = 0; i < len; i++)
        {
            cur.push_back(make_pair(nums[i][0], i));
            nums[i].erase(nums[i].begin());
        }
        sort(cur.begin(), cur.end(), [](pair<int, int> a, pair<int, int> b) -> bool {return a.first < b.first;});
        int res = cur[len - 1].first - cur[0].first;
        int small = cur[0].first;
        int big = cur[len - 1].first;
        while (true)
        {
            int index = cur[0].second;
            if (nums[index].empty())
            {
                break;
            }
            int l = 0;
            int r = len;
            while (l < r - 1)
            {
                int m = l + (r - l) / 2;
                if (cur[m].first < nums[index][0])
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            for (int i = 1; i <= l; i++)
            {
                cur[i - 1] = cur[i];
            }
            cur[l].first = nums[index][0];
            cur[l].second = index;
            if (cur[len - 1].first - cur[0].first < res)
            {
                res = cur[len - 1].first - cur[0].first;
                small = cur[0].first;
                big = cur[len - 1].first; 
            }
			nums[index].erase(nums[index].begin());
        }
        v_res.push_back(small);
        v_res.push_back(big);
        return v_res;
    }
};

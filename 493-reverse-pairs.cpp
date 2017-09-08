class Solution {
public:
    int cal(vector<int>& nums, int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        int m = l + (r - l) / 2;
        int res = cal(nums, l, m) + cal(nums, m + 1, r);
        int i = l;
        int j = m + 1;
        int k = m + 1;
        vector<int> temp;
        while (i <= m)
        {
            while (k <= r && (long long)nums[i] > (long long)nums[k] * 2)
            {
                k++;
            }
            res = res + (k - m - 1);
            
            while (j <= r && nums[j] < nums[i])
            {
                temp.push_back(nums[j]);
                j++;
            }
            temp.push_back(nums[i]);
            i++;
        }
        
        while (j <= r)
        {
            temp.push_back(nums[j]);
            j++;
        }
        
        for (int t = l; t <= r; t++)
        {
            nums[t] = temp[t - l];
        }
        
        return res;
    }
    
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
        {
            return 0;
        }
        
        return cal(nums, 0, len - 1);
    }
};

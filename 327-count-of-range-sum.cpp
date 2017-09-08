class Solution {
public:
    vector<long long> prev_sum;
    int low;
    int up;
    
    int cal(int l, int r)
    {
        if (l > r)
        {
            return 0;
        }
        if (l == r)
        {
            if (prev_sum[l] >= low && prev_sum[l] <= up)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        int m = l + (r - l) / 2;
        int res = cal(l, m) + cal(m + 1, r);
        int i = l;
        int j = m + 1;
        int k = m + 1;
        int u = m + 1;
        
        vector<long long> temp;
        
        while (i <= m)
        {
            while (k <= r && prev_sum[k] - prev_sum[i] < low)
            {
                k++;
            }
            
            while (u <= r && prev_sum[u] - prev_sum[i] <= up)
            {
                u++;
            }
            
            res = res + (u - k);
            
            while (j <= r && prev_sum[j] <= prev_sum[i])
            {
                temp.push_back(prev_sum[j]);
                j++;
            }
            temp.push_back(prev_sum[i]);
            i++;
        }
        
        while (j <= r)
        {
            temp.push_back(prev_sum[j]);
            j++;
        }
        
        for (int x = l; x <= r; x++)
        {
            prev_sum[x] = temp[x - l];
        }
        
        return res;
        
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        low = lower;
        up = upper;
        prev_sum.push_back(nums[0]);
        for (int i = 1; i < len; i++)
        {
            prev_sum.push_back(prev_sum[i - 1] + nums[i]);
        }
        return cal(0, len - 1);
    }
};

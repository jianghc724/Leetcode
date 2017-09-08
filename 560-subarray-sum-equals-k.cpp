class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 1; i <= nums.size(); i++)
        {
            int j = 0;
            long long int cur = 0;
            while (j != i)
            {
                cur += nums[j];
                j++;
            }
            if (cur == k)
            {
                res++;
            }
            for (int m = i; m < nums.size(); m++)
            {
                cur = cur - nums[m - i] + nums[m];
                if (cur == k)
                {
                    res++;
                }
            }
        }
        return res;
    }
};

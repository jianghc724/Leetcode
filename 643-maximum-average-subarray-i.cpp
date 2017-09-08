class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if (k == 0 || len == 0)
        {
            return 0;
        }
        int sum = 0;
        int cur = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        cur = sum;
        for (int i = k; i < len; i++)
        {
            sum = sum + (nums[i] - nums[i - k]);
            if (sum > cur)
            {
                cur = sum;
            }
        }
        return (double)cur / k;
    }
};

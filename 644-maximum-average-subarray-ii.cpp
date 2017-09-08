class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0 || len < k)
        {
            return 0;
        }
        double left_bound = -10000;
        double right_bound = 10000;
        while (right_bound - left_bound > 0.000001)
        {
            double partition = (left_bound + right_bound) / 2;
            if (cal(nums, partition, k))
            {
                left_bound = partition;
            }
            else
            {
                right_bound = partition;
            }
        }
        return left_bound;
    }
    
    bool cal(vector<int>& nums, double partition, int k)
    {
        int len = nums.size();
        double *pre_sum = new double[len];
        pre_sum[0] = nums[0] - partition;
        for (int i = 1; i < len; i++)
        {
            pre_sum[i] = pre_sum[i - 1] + nums[i] - partition;
        }
        if (pre_sum[k - 1] > 0)
        {
            delete[] pre_sum;
            return true;
        }
        double t = 0;
        for (int i = k; i < len; i++)
        {
            if (t > pre_sum[i - k])
            {
                t = pre_sum[i - k];
            }
            if (pre_sum[i] > t)
            {
                delete[] pre_sum;
                return true;
            }
        }
        delete[] pre_sum;
        return false;
    }
};

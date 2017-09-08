class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        vector<vector<long long>> res(len + 2, vector<long long>(len + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int i = 0;
        while (i <= len - 1)
        {
            int j = 1;
            while (i + j <= len)
            {
                int k = j;
                long long max_res = 0;
                while (k <= j + i)
                {
                    long long temp = 0;
                    temp = res[j][k - 1] + res[k + 1][j + i] + nums[j - 1] * nums[k] * nums[j + i + 1];
                    if (temp > max_res)
                    {
                        max_res = temp;
                    }
                    k++;
                }
                res[j][j + i] = max_res;
                j++;
            }
            i++;
        }
        return res[1][len];
    }
};

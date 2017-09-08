class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1)
        {
            return 0;
        }
        vector<int> step(len, INT_MAX);
        step[0] = 0;
        int last = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (i + nums[i] <= last)
            {
                continue;
            }
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i + j >= len)
                {
                    break;
                }
                if (step[i] + 1 < step[i + j])
                {
                    step[i + j] = step[i] + 1;
                    last = i + j;
                }
            }
        }
        return step[len - 1];
    }
};

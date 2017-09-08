class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
        {
            return true;
        }
        int max = 0;
        for (int i = 0; i < len; i++)
        {
            if (max < i)
            {
                return false;
            }
            if (i + nums[i] > max)
            {
                max = i + nums[i];
            }
            if (max >= len - 1)
            {
                return true;
            }
        }
    }
};

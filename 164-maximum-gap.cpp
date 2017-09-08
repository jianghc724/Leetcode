class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = 0;
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            if (nums[i + 1] - nums[i] > max)
            {
                max = nums[i + 1] - nums[i];
            }
        }
        return max;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int len = height.size();
        if (len <= 2)
        {
            return res;
        }
        vector<int> pre_max(len, -1);
        vector<int> after_max(len, -1);
        int p_max = -1;
        int a_max = -1;
        for (int i = 1; i < len; i++)
        {
            if (height[i - 1] > p_max)
            {
                p_max = height[i - 1];
            }
            if (height[len - i] > a_max)
            {
                a_max = height[len - i];
            }
            pre_max[i] = p_max;
            after_max[len - i - 1] = a_max; 
        }
        for (int i = 1; i < len - 1; i++)
        {
            if (height[i] < pre_max[i] && height[i] < after_max[i])
            {
                res = res + (min(pre_max[i], after_max[i]) - height[i]);
            }
        }
        return res;
    }
};

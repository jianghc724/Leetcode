class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> tail(len, INT_MAX);
        
        int size = 0;
        for (auto n : nums)
        {
            int i = 0;
            int j = size;
            while (i != j)
            {
                int m = (i + j) / 2;
                if (tail[m] < n)
                {
                    i = m + 1;
                }
                else
                {
                    j = m;
                }
            }
            
            tail[i] = n;
            if (i == size)
            {
                size++;
            }
        }
        
        return size;
    }
};

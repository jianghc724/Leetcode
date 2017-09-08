class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
        {
            return -1;
        }
        if (nums[0] == target)
        {
            return 0;
        }
        int l = 0;
        int r = len - 1;
        int m;
        bool flag = false;
		bool bigger = false;
		if (nums[0] > target)
		{
			bigger = true;
		}
        while (l < r - 1)
        {
            if (nums[l] < nums[r])
            {
                flag = true;
            }
			m = l + (r - l) / 2;
            int temp = nums[m];
            if (temp == target)
            {
                return m;
            }
            if (nums[m] > target)
            {
                if (flag)
                {
                    r = m;
                }
				else if (bigger) 
                {
                    if (nums[m] > nums[l])
					{
						l = m;
					}
					else
					{
						r = m;
					}
                }
                else
                {
                    if (nums[m] > nums[l])
					{
						r = m;
					}
					else
					{
						l = m;
					}
                }
            }
            else
            {
				if (flag)
                {
                    l = m;
                }
				else if (bigger) 
                {
                    if (nums[m] > nums[l])
					{
						r = m;
					}
					else
					{
						l = m;
					}
                }
                else
                {
                    if (nums[m] > nums[l])
					{
						l = m;
					}
					else
					{
						r = m;
					}
                }
            }
        }
        
        
        if (nums[l] == target)
        {
            return l;
        }
        else if (nums[r] == target)
        {
            return r;
        }

		return -1;
    }
};

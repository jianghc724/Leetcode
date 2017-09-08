class Solution {
public:
    vector<int> counts;
    vector<int> index;
    
    void cal(vector<int>& nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int m = l + (r - l) / 2;
        cal(nums, l, m);
        cal(nums, m + 1, r);
        int i = l;
        int k = m + 1;
        vector<int> temp;
        while (i <= m)
        {
            while (k <= r && nums[index[i]] > nums[index[k]])
            {
                temp.push_back(index[k]);
                k++;
            }
            counts[index[i]] = counts[index[i]] + (k - m - 1);
            temp.push_back(index[i]);
            i++;
        }
        
        while (k <= r)
        {
            temp.push_back(index[k]);
            k++;
        }
        
        for (int j = l; j <= r; j++)
        {
            index[j] = temp[j - l];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            counts.push_back(0);
            index.push_back(i);
        }
        cal(nums, 0, len - 1);
        return counts;
    }
};

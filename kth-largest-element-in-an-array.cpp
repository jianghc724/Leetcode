class Solution {
public:
    int kth;
    
    int findKthLargest(vector<int>& nums, int k) {
        kth = k;
        vector<int> res = cal(nums, 0, nums.size() - 1);
        return *(res.end() - 1);
    }
    
    vector<int> cal(vector<int>& nums, int l, int r)
    {
        vector<int> res;
        if (l > r)
        {
            return res;
        }
        if (l == r)
        {
            vector<int> res;
            res.push_back(nums[l]);
            return res;
        }
        int m = l + (r - l) / 2;
        vector<int> left = cal(nums, l, m);
        vector<int> right = cal(nums, m + 1, r);
        int l_len = left.size();
        int r_len = right.size();
        int n = 0;
        int i = 0;
        int j = 0;
        while (n < kth && i < l_len && j < r_len)
        {
            if (left[i] > right[j])
            {
                res.push_back(left[i]);
                i++;
            }
            else
            {
                res.push_back(right[j]);
                j++;
            }
            n++;
        }
        while (n < kth && i < l_len)
        {
            res.push_back(left[i]);
            i++;
            n++;
        }
        while (n < kth && j < r_len)
        {
            res.push_back(right[j]);
            j++;
            n++;
        }
        return res;
    }
};

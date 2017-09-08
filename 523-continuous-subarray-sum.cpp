class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k == 0)
        {
            set<int> _pre_sum;
            int pre_sum = 0;
            int pre = -1;
            for (auto x : nums)
            {
                if (x == 0)
                {
                    if (pre == 0)
                    {
                        return true;
                    }
                    pre = x;
                    continue;
                }
                pre_sum += x;
                if (_pre_sum.find(pre_sum) != _pre_sum.end()) return true;
                _pre_sum.insert(pre_sum);
                pre = x;
            }
            return false;
        }
        k = abs(k);
        set<int> isUsed;
        int pre_sum = 0;
        int pre = -1;
        bool flag = false;
        for (auto x : nums)
        {
            if (x % k == 0)
            {
                if (flag && pre % k== 0)
                {
                    return true;
                }
                flag = true;
                pre = x;
                continue;
            }
            pre_sum = (pre_sum + x) % k;
            if (pre_sum == 0) return true;
            if (isUsed.find(pre_sum) != isUsed.end()) return true;
            isUsed.insert(pre_sum);
            pre = x;
            flag = true;
        }
        return false;
    }
};

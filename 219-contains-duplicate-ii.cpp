class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> is_exist;
        int i = 0;
        for (auto x : nums)
        {
            map<int, int>::iterator it = is_exist.find(x);
            if (it != is_exist.end())
            {
                if (i <= k + it->second)
                {
                    return true;
                }
                is_exist[x] = i;
            }
            else
            {
                is_exist.insert(make_pair(x, i));
            }
            i++;
        }
        return false;
    }
};

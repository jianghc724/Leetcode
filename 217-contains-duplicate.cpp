class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> is_exist;
        for (auto x : nums)
        {
            if (is_exist.find(x) != is_exist.end())
            {
                return true;
            }
            is_exist.insert(x);
        }
        return false;
    }
};

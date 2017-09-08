class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int> n;
        for (auto x : nums)
        {
            n.insert(x);
        }
        return (n.find(target) != n.end());
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int s = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[s / 2];
        int b = a;
        if (!(s % 2)) {
            b = nums[s / 2 - 1];
        }
        int sum1 = 0;
        int sum2 = 0;
        for (auto x : nums) {
            sum1 += abs(a - x);
            sum2 += abs(b - x);
        }
        
        if (sum1 < sum2) {
            return sum1;
        } else {
            return sum2;
        }
    }
};

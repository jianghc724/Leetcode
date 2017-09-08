class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int s = nums.size();
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            int a = 0;
            int b = 0;
            for (int j = 0; j < s; j++) {
                if (nums[j] % 2) {
                    a++;
                } else {
                    b++;
                }
                nums[j] = nums[j] >> 1;
            }
            sum = sum + a * b;
        }
        return sum;
    }
};

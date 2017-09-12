class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size();
        int i = l - 1;
        while (i > 0) {
            if (nums[i] <= nums[i - 1]) {
                i--;
                continue;
            }
            
            int j = i;
            while (j != l && nums[i - 1] < nums[j]) {
                j++;
            }
            int temp = nums[i - 1];
            nums[i - 1] = nums[j - 1];
            nums[j - 1] = temp;
            int start = i;
            int end = l - 1;
            while (start < end) {
                int t = nums[start];
                nums[start] = nums[end];
                nums[end] = t;
                start++;
                end--;
            }
            break;
        }
        
        if (i == 0) {
            int start = 0;
            int end = l - 1;
            while (start < end) {
                int t = nums[start];
                nums[start] = nums[end];
                nums[end] = t;
                start++;
                end--;
            }
        }
    }
};

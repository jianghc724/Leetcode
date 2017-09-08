class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int b = INT_MAX;
        for (auto x : nums) {           
            if (x < b) {
                b = x;
            }
        }
        
        for (auto x : nums) {
            sum = sum + (x - b);
        }
        
        return sum;
    }
};

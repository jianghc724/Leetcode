class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        bool* result = new bool[len];
        int ans = len + 1;
        for (int i = 0; i < len; i++)
        {
            result[i] = false;
        }
        vector<int>::iterator r = nums.begin();
        for (; r != nums.end(); r++)
        {
            int num = *r;
            if ((num <= 0) || (num > len))
            {
                continue;
            }
            result[num - 1] = true;
        }
        for (int i = 0; i < len; i++)
        {
            if (!result[i])
            {
                ans = i + 1;
                break;
            }
        }
        delete[] result;
        return ans;
    }
};

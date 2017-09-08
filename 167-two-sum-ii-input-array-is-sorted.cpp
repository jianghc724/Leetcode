class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int mid = target / 2;
        int i = 0;
        int j = i;
        while (numbers[i] < mid)
        {
            j = i;
            i++;
        }
        
        vector<int> res;
        if (i != numbers.size() - 1)
        {
            if (numbers[i] + numbers[i + 1] == target)
            {
                res.push_back(i + 1);
                res.push_back(i + 2);
                return res;
            }
        }
        
        while (true)
        {
            if (numbers[j] + numbers[i] == target)
            {
                res.push_back(j + 1);
                res.push_back(i + 1);
                return res;
            }
            else if (numbers[j] + numbers[i] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
};

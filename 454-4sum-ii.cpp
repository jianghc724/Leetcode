class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> num_map;
        int res = 0;
        for (auto x : A)
        {
            for (auto y : B)
            {
                num_map[x + y]++;
            }
        }
        
        for (auto x : C)
        {
            for (auto y : D)
            {
                if (num_map.find(-x-y) != num_map.end())
                {
                    res += num_map[-x-y];
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
        {
            return 0;
        }
        int min = prices[0];
        int max = 0;
        for (int i = 1; i < len; i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
                continue;
            }
            
            if (prices[i] - min > max)
            {
                max = prices[i] - min;
            }
        }
        return max;
    }
};

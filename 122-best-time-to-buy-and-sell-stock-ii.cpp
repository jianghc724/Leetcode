class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
        {
            return 0;
        }
        int i = 0;
        int start = 0;
        int res = 0;
        while (i < len)
        {
            while (prices[i] >= prices[i + 1] && i < len - 1)
            {
                i++;
            }
            if (i == len - 1)
            {
                break;
            }
            start = i;
            while (prices[i] <= prices[i + 1] && i < len - 1)
            {
                i++;
            }
            res = res + prices[i] - prices[start];
            if (i == len - 1)
            {
                break;
            }
        }
        return res;
    }
};

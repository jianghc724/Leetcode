class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> can;
        int len = candies.size();
        int bro = 0;
        int sis = 0;
        int i = 0;
        for (auto x : candies)
        {
            if (can.find(x) != can.end())
            {
                bro++;
            }
            else
            {
                can.insert(make_pair(x, sis));
                sis++;
            }
            i++;
            if (sis == len / 2)
            {
                return sis;
            }
            if (bro == len / 2)
            {
                break;
            }
        }
        
        for (int j = i; j < len; j++)
        {
            if (can.find(candies[j]) == can.end())
            {
                can.insert(make_pair(candies[j], sis));
                sis++;
            }
        }
        
        return sis;
    }
};

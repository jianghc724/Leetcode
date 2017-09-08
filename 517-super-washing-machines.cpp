class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        if (len == 0)
        {
            return 0;
        }
        int res = 0;
        int total = 0;
        for (auto x : machines)
        {
            total += x;
        }
        if (total % len != 0)
        {
            return -1;
        }
        total /= len;
        vector<int> net_clothes;
        int net = 0;
        for (auto x : machines)
        {
            net = net + x - total;
            res = max(x - total, res);
            net_clothes.push_back(net);
            res = max(abs(net), res);
        }
        return res;
    }
};

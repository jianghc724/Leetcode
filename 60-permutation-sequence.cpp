class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        int res = 1;
        int m = n;
        while (m != 0)
        {
            res *= m;
            m--;
        }
        vector<int> order;
        for (int i = 0; i < n; i++)
        {
            order.push_back(i + 1);
        }
		m = n;
        while (k != 1)
        {
            res /= m;
            m--;
            int cur = 0;
            while (k > res && cur < m)
            {
                k -= res;
                cur++;
            }
            s = s + to_string(order[cur]);
            order.erase(order.begin() + cur);
        }
        
        int len = order.size();
        for (int i = 0; i < len; i++)
        {
            s = s + to_string(order[i]);
        }
        return s;
    }
};

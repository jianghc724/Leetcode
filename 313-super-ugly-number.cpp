class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<int> cur;
        cur.insert(1);
        for (int i = 1; i < n; i++) {
            set<int>::iterator it = cur.begin();
            int num = *it;
            cur.erase(it);
            for (auto p : primes) {
                if (INT_MAX / p > num) {
                    cur.insert(num * p);
                }
            }
        }
        set<int>::iterator it = cur.begin();
        int num = *it;
        return num;
    }
};

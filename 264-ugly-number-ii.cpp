class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        set<int> cur;
        cur.insert(2);
        cur.insert(3);
        cur.insert(5);
        for (int i = 2; i < n; i++) {
            set<int>::iterator it = cur.begin();
            int num = *it;
            cur.erase(it);
            if (INT_MAX / 2 >= num) {
                cur.insert(num * 2);
            }
            if (INT_MAX / 3 >= num) {
                cur.insert(num * 3);
            }
            if (INT_MAX / 5 >= num) {
                cur.insert(num * 5);
            }
        }
        set<int>::iterator it = cur.begin();
        int num = *it;
        return num;
    }
};

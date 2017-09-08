class Solution {
public:
    string solveEquation(string equation) {
        int left_x = 0;
        int left_con = 0;
        int right_x = 0;
        int right_con = 0;
        bool left = true;
        bool flag = true;
        bool isSet = false;
        int res = 0;
        for (auto c : equation) {
            if (c == '=') {
                if (!flag) {
                    res = -res;
                }
                left_con += res;
                left = false;
                flag = true;
                res = 0;
                isSet = false;
            } else if (c == 'x') {
                if (!isSet) {
                    res = 1;
                }
                if (!flag) {
                    res = -res;
                }
                if (left) {
                    left_x += res;
                } else {
                    right_x += res;
                }
                res = 0;
                isSet = false;
            } else if (c == '+') {
                if (!flag) {
                    res = -res;
                }
                if (left) {
                    left_con += res;
                } else {
                    right_con += res;
                }
                flag = true;
                res = 0;
                isSet = false;
            } else if (c == '-') {
                if (!flag) {
                    res = -res;
                }
                if (left) {
                    left_con += res;
                } else {
                    right_con += res;
                }
                flag = false;
                res = 0;
                isSet = false;
            } else {
                res = res * 10 + (c - '0');
                isSet = true;
            }
        }
        
        if (!flag) {
            res = -res;
        }
        right_con += res;
        
        if (left_x == right_x && left_con == right_con) {
            return "Infinite solutions";
        } else if (left_x == right_x) {
            return "No solution";
        } else {
            return "x=" + to_string((right_con - left_con) / (left_x - right_x));
        }
    }
};

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1)
        {
            string result;
            result.push_back(n[0] - 1);
            return result;
        }
        if (n[0] == '1')
        {
            bool flag = true;
            for (int i = 1; i < len - 1; i++)
            {
                if (n[i] != '0')
                {
                    flag = false;
                    break;
                }
            }
            if (n[len - 1] != '0' && n[len - 1] != '1')
            {
                flag = false;
            }
            if (flag)
            {
                string result;
                for (int i = 0; i < len - 1; i++)
                {
                    result.push_back('9');
                }
                return result;
            }
        }
        if (n[0] == '9')
        {
            bool flag = true;
            for (int i = 1; i < len; i++)
            {
                if (n[i] != '9')
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                string result;
                result.push_back('1');
                for (int i = 0; i < len - 1; i++)
                {
                    result.push_back('0');
                }
                result.push_back('1');
                return result;
            }
        }
        int last = (len + 1) / 2;
        bool flag = true;
        double cur = 0;
        int _cur = 0;
        double ori = 0;
        bool is_even = true;
        if (len % 2 != 0)
        {
            is_even = false;
        }
        for (int i = 0; i < last; i++)
        {
            _cur = _cur * 10 + n[i] - '0';
            if (n[i] != n[len - 1 - i])
            {
                flag = false;
            }
        }
        ori = _cur;
        if (flag)
        {
            _cur--;
        }
        cur = _cur;
        for (int i = last; i < len; i++)
        {
            ori = ori * 10 + n[i] - '0';
        }
        int temp = _cur / 10;
        if (is_even)
        {
            cur = cur * 10 + _cur % 10;
        }
        while (temp != 0)
        {
            int t = temp % 10;
            temp = temp / 10;
            cur = cur * 10 + t;
        }
        double delta = ori - cur;
        int _next_cur = _cur;
        double next_delta = 0;
        if (delta > 0)
        {
            _next_cur++;
        }
        else
        {
            _next_cur--;
        }
        if (flag)
        {
            _next_cur = _cur + 2;
        }
        temp = _next_cur / 10;
        double next_cur = _next_cur;
        if (is_even)
        {
            next_cur = next_cur * 10 + _next_cur % 10;
        }
        while (temp != 0)
        {
            int t = temp % 10;
            temp = temp / 10;
            next_cur = next_cur * 10 + t;
        }
        bool small_flag = true;
        if (delta > 0)
        {
            next_delta = next_cur - ori;
        }
        else
        {
            next_delta = ori - next_cur;
            delta = -delta;
            small_flag = false;
        }
        string next_cur_res;
        string cur_res;
        string cur_str;
        string next_cur_str;
        while (_cur != 0)
        {
            int t = _cur % 10;
            int _t = _next_cur % 10;
            _cur = _cur / 10;
            _next_cur = _next_cur / 10;
            cur_str.insert(cur_str.begin(), t + '0');
            next_cur_str.insert(next_cur_str.begin(), _t + '0');
        }
        cur_res = cur_str;
        next_cur_res = next_cur_str;
        int _len = cur_str.length();
        if (is_even)
        {
            cur_res.push_back(cur_str[_len - 1]);
            next_cur_res.push_back(next_cur_str[_len - 1]);
        }
        for (int i = _len - 2; i >= 0; i--)
        {
            cur_res.push_back(cur_str[i]);
            next_cur_res.push_back(next_cur_str[i]);
        }
        if (next_delta > delta)
        {
            return cur_res;
        }
        else if (next_delta < delta)
        {
            return next_cur_res;
        }
        else
        {
            if (small_flag)
            {
                return cur_res;
            }
            else
            {
                return next_cur_res;
            }
        }
    }
};

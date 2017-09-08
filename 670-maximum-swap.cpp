class Solution {
public:
    int maximumSwap(int num) {
        int pre_fir = -1;
        int pre_sec = -1;
        int fir = -1;
        int sec = -1;
        int s = -1;
        int a = -1;
        int _num = num;
        while (_num != 0) {
            int n = _num % 10;
            _num /= 10;
			s++;
            if (n > a) {
                if (sec != -1)
				{
					pre_fir = fir;
					pre_sec = sec;
				}
                fir = s;
                sec = -1;
                a = n;
            } else if (n == a) {
                continue;
            } else {
                sec = s;
            }
        }
        
        if (sec == -1 && pre_sec == -1) {
            return num;
        }
        
        if (sec == -1) {
            return swap(num, pre_fir, pre_sec);
        }
        
        return swap(num, fir, sec);
    }
    
    int swap(int num, int f, int s) {
        vector<int> digit;
        while (num != 0) {
            digit.push_back(num % 10);
            num /= 10;
        }
        
        int temp = digit[f];
        digit[f] = digit[s];
        digit[s] = temp;
        
        int len = digit.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            res = res * 10 + digit[len - 1 - i];
        }
        
        return res;
    }
};

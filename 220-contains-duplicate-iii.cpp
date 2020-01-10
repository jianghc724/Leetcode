class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k <= 0)
        {
            return false;
        }
        vector<int> sortedNum;
        vector<int>::iterator i = nums.begin();
        int j = 0;
        while ((j <= k) && (i != nums.end())) {
            sortedNum.push_back(*i);
            i++;
            j++;
        }
        sort(sortedNum.begin(), sortedNum.end());
        vector<int>::iterator m = sortedNum.begin();
        vector<int>::iterator n = sortedNum.begin() + 1;
        for (; n < sortedNum.end(); n++) {
            long long int r = 0;
            if (*m > *n) {
                r = (long long)*m - (long long)*n;
            } else {
                r = (long long)*n - (long long)*m;
            }
            if (r <= (long long)t) {
                return true;
            }
            m++;
        }
        m = nums.begin();
        for (; i < nums.end(); i++) {
            int rem = *m;
            int ins = *i;
            int left = 0;
            int right = k;
            int mid = (right + left) / 2;
            while (right > left) {
                mid = (right + left) / 2;
                if (sortedNum[mid] == rem) {
                    break;
                } else if (sortedNum[mid] < rem) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            mid = (right + left) / 2;
            sortedNum.erase(sortedNum.begin() + mid);
            if (ins >= sortedNum.back()) {
                long long int r = 0;
                if (ins > sortedNum.back()) {
                    r = (long long)ins - (long long)sortedNum.back();
                } else {
                    r = (long long)sortedNum.back() - (long long)ins;
                }
                if (r <= (long long)t) {
                    return true;
                }
                m++;
                continue;
            }
            left = 0;
            right = k;
            while (right > left) {
                mid = (left + right) / 2;
                if (sortedNum[mid] == ins) {
                    break;
                }
                else if (sortedNum[mid] < ins) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            mid = (left + right) / 2;
            if (mid > 0) {
                long long int r = 0;
                if (ins > sortedNum[mid - 1]) {
                    r = (long long)ins - (long long)sortedNum[mid - 1];
                } else {
                    r = (long long)sortedNum[mid - 1] - (long long)ins;
                }
                if (r <= (long long)t) {
                    return true;
                }
            }
            long long int _r = 0;
            if (ins > sortedNum[mid]) {
                _r = (long long)ins - (long long)sortedNum[mid];
            } else {
                _r = (long long)sortedNum[mid] - (long long)ins;
            }
            if (_r <= (long long)t) {
                return true;
            }
            sortedNum.insert(sortedNum.begin() + mid, ins);
            m++;
        }
        return false;
    }
};

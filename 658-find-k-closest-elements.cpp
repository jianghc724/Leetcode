class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (k == 0) {
            return res;
        }
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                left = mid;
                right = mid;
                break;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int count = 0;
        
        if (left > right) {
            right = left;
            left = right - 1;
        } else {
            if (arr[left] != x) {
                right = left + 1;
            } else {
                res.push_back(x);
                left--;
                right++;
                count++;
            }
        }
        
        while (count < k && right != arr.size() && left != -1) {
            if (arr[right] - x < x - arr[left]) {
                res.push_back(arr[right]);
                right++;
            } else {
                res.insert(res.begin(), arr[left]);
                left--;
            }
            count++;
        }
        
        if (count < k) {
            if (left == -1) {
                while (count < k) {
                    res.push_back(arr[right]);
                    right++;
                    count++;
                }
            } else {
                while (count < k) {
                    res.insert(res.begin(), arr[left]);
                    left--;
                    count++;
                }
            }
        }
        
        return res;
    }
};

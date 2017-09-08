class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int half_len = (len1 + len2 + 1) / 2;
        bool is_odd = (len1 + len2) % 2;
        if (len1 > len2)
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int _temp = len1;
            len1 = len2;
            len2 = _temp;
        }
        int left_bound = 0;
        int right_bound = len1;
        int mid = (left_bound + right_bound + 1) / 2;
        while (left_bound <= right_bound)
        {
            mid = (left_bound + right_bound + 1) / 2;
            int _mid = half_len - mid;
            if (mid < len1 && nums1[mid] < nums2[_mid - 1])
            {
                left_bound = mid + 1;
                
            }
            else if (mid > 0 && nums1[mid - 1] > nums2[_mid])
            {
                right_bound = mid - 1;
            }
            else
            {
                int a = 0;
                if (mid == 0)
                {
                    a = nums2[_mid - 1];
                }
                else if (_mid == 0)
                {
                    a = nums1[mid - 1];
                }
                else
                {
                    a = max(nums1[mid - 1], nums2[_mid - 1]);
                }
                if (is_odd)
                {
                    return a;
                }
                int b = 0;
                if (mid == len1)
                {
                    b = nums2[_mid];
                }
                else if (_mid == len2)
                {
                    b = nums1[mid];
                }
                else
                {
                    b = min(nums1[mid], nums2[_mid]);
                }
                return ((double)(a + b)) / 2;
            }
        }
    }
};

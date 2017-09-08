class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        vector<string>::iterator r = timePoints.begin();
        for (; r != timePoints.end(); r++)
        {
            string timePoint = *r;
            int hour = (int)(timePoint[0] - '0') * 10 + (int)(timePoint[1] - '0');
            int minute = (int)(timePoint[3] - '0') * 10 + (int)(timePoint[4] - '0');
            times.push_back(hour * 60 + minute);
        }
        std::sort(times.begin(), times.end());
        int min = times.front() - times.back() + 1440;
        vector<int>::iterator r2 = times.begin();
        int pre = *r2;
        int cur = pre;
        r2++;
        for (;r2 != times.end(); r2++)
        {
            cur = *r2;
            if (cur - pre < min)
            {
                min = cur - pre;
            }
            pre = cur;
        }
        return min;
    }
};

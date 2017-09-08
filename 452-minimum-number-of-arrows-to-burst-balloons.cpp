class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) -> bool {if (a.second != b.second) return a.second < b.second; return a.first < b.first;});
        int res = 0;
        while (!points.empty())
        {
            res++;
            int cur = points.front().second;
            points.erase(points.begin());
            while (!points.empty() && points.front().first <= cur)
            {
                points.erase(points.begin());
            }
        }
        return res;
    }
};

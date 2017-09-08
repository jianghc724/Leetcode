/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int s = points.size();
        if (s <= 2)
        {
            return s;
        }
        int result = 2;
        vector<double> k;
        vector<int> r;
        for (int i = 0; i < s; i++)
        {
            int i_x = points[i].x;
            int i_y = points[i].y;
            int c = 1;
            int same = 2;
            k.clear();
            r.clear();
            for (int j = i + 1; j < s; j++)
            {
                int j_x = points[j].x;
                int j_y = points[j].y;
                if (j_y == i_y)
                {
                    c++;
                    if (c > result)
                    {
                        result = c;
                    }
                    if (i_x == j_x)
                    {
                        for (int m = 0; m < r.size(); m++)
                        {
                            r[m]++;
                            if (r[m] > result)
                            {
                                result = r[m];
                            }
                        }
                        same++;
                    }
                    continue;
                }
                double _k = (double)(j_x - i_x) / (double)(j_y - i_y);
                int k_s = k.size();
                bool flag = true;
                for (int m = 0; m < k_s; m++)
                {
                    if (k[m] == _k)
                    {
                        r[m]++;
                        if (r[m] > result)
                        {
                            result = r[m];
                        }
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    k.push_back(_k);
                    r.push_back(same);
                    if (same > result)
                    {
                        result = same;
                    }
                }
            }
        }
        return result;
    }
};

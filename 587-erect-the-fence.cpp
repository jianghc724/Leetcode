/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#define PI 3.1415926

class myPoint {
public:
    int index;
    int x;
    int y;
    double degree;
    
public:
    myPoint(int i, int _x, int _y){index = i; x = _x; y = _y;}
};

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int len = points.size();
		if (len <= 3)
		{
			return points;
		}
        int minNode = 0;
        for (int i = 0; i < len; i++)
        {
            if (points[i].y < points[minNode].y || (points[i].y == points[minNode].y && points[i].x < points[minNode].x))
            {
                minNode = i;
            }
        }
        vector<myPoint*> allOtherPoints;
        for (int i = 0; i < len; i++)
        {
            if (i == minNode)
            {
                continue;
            }
            myPoint* p = new myPoint(i, points[i].x, points[i].y);
            if (points[i].x == points[minNode].x)
            {
                p->degree = 90;
            }
            else
            {
                double temp = atan((double)(points[i].y - points[minNode].y) / (double)(points[i].x - points[minNode].x)) * 180 / PI;
                if (temp < 0)
                {
                    temp += 180;
                }
                p->degree = temp;
            }
			allOtherPoints.push_back(p);
        }
        sort(allOtherPoints.begin(), allOtherPoints.end(), [](myPoint* a, myPoint* b) -> bool {if (a->degree != b->degree) return a->degree < b->degree; if (a->y != b-> y) return a->y < b->y; return a->x < b->x;});
        vector<int> resNodes;
        vector<int> resMyPoint;
        resNodes.push_back(minNode);
        resNodes.push_back(allOtherPoints[0]->index);
        resNodes.push_back(allOtherPoints[1]->index);
        resMyPoint.push_back(-1);
        resMyPoint.push_back(0);
        resMyPoint.push_back(1);
        for (int i = 2; i < len - 1; i++)
        {
            int cur = allOtherPoints[i]->index;
            int top = resNodes.size() - 1;
            while (true)
            {
                double temp = mul(points, cur, resNodes[top], resNodes[top - 1]);
                if (temp < 0)
                {
                    break;
                }
                if (temp == 0)
                {
                    double d1 = allOtherPoints[i]->degree;
                    double d2 = allOtherPoints[resMyPoint[top]]->degree;
                    if (d1 != d2)
                    {
                        break;
                    }
                }
                top--;
                resNodes.pop_back();
                resMyPoint.pop_back();
                if (top == 0)
                {
                    break;
                }
            }
            resNodes.push_back(cur);
            resMyPoint.push_back(i);
        }
        int res_len = resNodes.size();
        vector<Point> res;
        res.push_back(points[resNodes[0]]);
        res.push_back(points[resNodes[1]]);
        double d = allOtherPoints[resMyPoint[1]]->degree;
        for (int i = resMyPoint[1] - 1; i >= 0; i--)
        {
            if (allOtherPoints[i]->degree == d)
            {
                res.push_back(points[allOtherPoints[i]->index]);
            }
            else
            {
                break;
            }
        }
        if (res_len == 2)
        {
            return res;
        }
        for (int i = 2; i < res_len - 1; i++)
        {
            res.push_back(points[resNodes[i]]);
        }
        d = allOtherPoints[resMyPoint[res_len - 1]]->degree;
        for (int i = resMyPoint[res_len - 1] - 1; i >= 0; i--)
        {
            if (allOtherPoints[i]->degree == d)
            {
                res.push_back(points[allOtherPoints[i]->index]);
            }
            else
            {
                break;
            }
        }
        res.push_back(points[resNodes[res_len - 1]]);
        return res;
    }
    
    double mul(vector<Point>& points, int i, int j, int k) {
		return ((points[i].x - points[k].x) * (points[j].y - points[k].y) - (points[j].x - points[k].x) * (points[i].y - points[k].y));
    }
};

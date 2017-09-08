class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int _x[4] = {0, 0, 0, 0};
        int _y[4] = {0, 0, 0, 0};
        int pos_x[4] = {0, -1, 0, 1};
        int pos_y[4] = {1, 0, -1, 0};
        int pre_pre_x = 0;
        int pre_pre_y = 0;
        int pre_x = 0;
        int pre_y = 0;
        int cur_x = 0;
        int cur_y = 0;
        int len = x.size();
        for (int i = 0; i < len; i++)
        {
            _x[(i + 2) % 4] = pre_pre_x;
            _y[(i + 2) % 4] = pre_pre_y;
            pre_pre_x = pre_x;
            pre_pre_y = pre_y;
            pre_x = cur_x;
            pre_y = cur_y;
            cur_x = cur_x + pos_x[i % 4] * x[i];
            cur_y = cur_y + pos_y[i % 4] * x[i];
            if (i % 4 == 0 && i != 0)
            {
                if ((_y[1] <= cur_y && _y[1] >= pre_y && _x[2] <= cur_x && _x[1] >= cur_x) ||
                   (_y[3] <= cur_y && _y[3] >= pre_y && _x[3] <= cur_x && _x[0] >= cur_x))
                {
                    return true;
                }
            }
            else if (i % 4 == 1 && i != 1)
            {
                if ((_x[1] >= cur_x && _x[1] <= pre_x && _y[0] <= cur_y && _y[1] >= cur_y) ||
                   (_x[3] <= cur_x && _x[3] >= pre_x && _y[3] <= cur_y && _y[2] >= cur_y))
                {
                    return true;
                }
            }
            else if (i % 4 == 2 && i != 2)
            {
                if ((_y[1] <= pre_y && _y[1] >= cur_y && _x[2] <= cur_x && _x[1] >= cur_x) ||
                   (_y[3] <= pre_y && _y[3] >= cur_y && _x[3] <= cur_x && _x[0] >= cur_x))
                {
                    return true;
                }
            }
            else if (i % 4 == 3)
            {
                if ((_x[1] >= pre_x && _x[1] <= cur_x && _y[0] <= cur_y && _y[1] >= cur_y) ||
                   (_x[3] <= pre_x && _x[3] >= cur_x && _y[3] <= cur_y && _y[2] >= cur_y))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

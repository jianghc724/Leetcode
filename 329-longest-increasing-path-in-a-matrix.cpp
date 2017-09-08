class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
        {
            return 0;
        }
        int col = matrix[0].size();
        if (col == 0)
        {
            return 0;
        }
        vector<vector<int>> res(row, vector<int>(col, 0));
        int m = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m = max(m, cal(i, j, matrix, res));
            }
        }
        return m;
    }
    
    int cal(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& res)
    {
        if (res[i][j])
        {
            return res[i][j];
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int _x[4] = {0, 1, 0, -1};
        int _y[4] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++)
        {
            int _i = i + _x[k];
            int _j = j + _y[k];
            if ((_i == -1) || (_j == -1) || (_i == row) || (_j == col))
            {
                continue;
            }
            if (matrix[i][j] < matrix[_i][_j])
            {
                res[i][j] = max(res[i][j], cal(_i, _j, matrix, res));
            }
        }
        res[i][j]++;
        return res[i][j];
    }
};

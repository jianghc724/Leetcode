class NumMatrix {
public:
    vector<vector<int>> pre_sum;
    int row;
    int col;
    
    NumMatrix(vector<vector<int>> matrix) {
        row = matrix.size();
        if (row == 0)
        {
            col = 0;
            return;
        }
        col = matrix[0].size();
        if (col == 0)
        {
            return;
        }
        
        for (int i = 0; i < row; i++)
        {
            vector<int> temp(1, matrix[i][0]);
            for (int j = 1; j < col; j++)
            {
                temp.push_back(temp[j - 1] + matrix[i][j]);
            }
            pre_sum.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row2 < row1 || col2 < col1)
        {
            return 0;
        }
        int res = 0;
        for (int i = row1; i <= row2; i++)
        {
            if (col1 != 0)
            {
                res = res + (pre_sum[i][col2] - pre_sum[i][col1 - 1]);
            }
            else
            {
                res = res + pre_sum[i][col2];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

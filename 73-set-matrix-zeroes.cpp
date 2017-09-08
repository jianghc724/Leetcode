class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int col = matrix[0].size();
        vector<bool> r(row, false);
        vector<bool> c(col, false);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    c[j] = true;
                    r[i] = true;
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (r[i]) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (c[j]) {
                for (int i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

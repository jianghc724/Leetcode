class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return 0;
        }
        int _res = 0;
        vector<vector<int>> res(row + 1, vector<int>(col + 1, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    res[i + 1][j + 1] = 0;
                } else {
                    res[i + 1][j + 1] = 1 + min(res[i][j], min(res[i + 1][j], res[i][j + 1]));
                    if (res[i + 1][j + 1] > _res) {
                        _res = res[i + 1][j + 1];
                    }
                }
            }
        }
        
        return _res * _res;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix.size();
        for (int i = 0; i < s / 2; i++) {
            for (int j = i; j < s - 1 - i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[s - 1 - j][i];
                matrix[s - 1 - j][i] = matrix[s - 1 - i][s - 1 - j];
                matrix[s - 1 - i][s - 1 - j] = matrix[j][s - 1 - i];
                matrix[j][s - 1 - i] = temp;
            }
        }
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        if (row == 0)
        {
            return 1;
        }
        int col = dungeon[0].size();
        if (col == 0)
        {
            return 1;
        }
        vector<vector<int>> HP(row + 1, vector<int>(col + 1, INT_MAX));
        
        HP[row][col - 1] = 1;
        HP[row - 1][col] = 1;
        
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                int temp = min(HP[i][j + 1], HP[i + 1][j]);
                temp = temp - dungeon[i][j];
                if (temp > 0)
                {
                    HP[i][j] = temp;
                }
                else
                {
                    HP[i][j] = 1;
                }
            }
        }
        
        return HP[0][0];
    }
};

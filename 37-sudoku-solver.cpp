class Solution {
public:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> cell;
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<bool> temp(9, true);
        for (int i = 0; i < 9; i++)
        {
            row.push_back(temp);
            col.push_back(temp);
            cell.push_back(temp);
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    row[i][board[i][j] - '1'] = false;
                    col[j][board[i][j] - '1'] = false;
                    cell[i / 3 * 3 + j / 3][board[i][j] - '1'] = false;
                }
            }
        }
        dfs(0, board);
    }
    
    bool dfs(int num, vector<vector<char>>& board) {
        if (num == 81)
        {
            return true;
        }
        int r = num / 9;
        int c = num % 9;
        
        if (board[r][c] != '.')
        {
            bool flag = dfs(num + 1, board);
			if (flag)
			{
				return true;
			}
        }
        else
		{
			for (int i = 0; i < 9; i++)
			{
				if (row[r][i] && col[c][i] && cell[r / 3 * 3 + c / 3][i])
				{
					board[r][c] = (char)(i + '1');
					row[r][i] = false;
					col[c][i] = false;
					cell[r / 3 * 3 + c / 3][i] = false;
					bool flag = dfs(num + 1, board);
					if (flag)
					{
						return true;
					}
					board[r][c] = '.';
					row[r][i] = true;
					col[c][i] = true;
					cell[r / 3 * 3 + c / 3][i] = true;
				}
			}
		}
        
        return false;
    }
};

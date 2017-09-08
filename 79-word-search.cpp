class Solution {
public:
    vector<vector<bool>> isUsed;
    int row;
    int col;
    int len;
    string key;
    
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        if (row == 0)
        {
            return false;
        }
        col = board[0].size();
        if (col == 0)
        {
            return false;
        }
        key = word;
        len = key.length();
        if (len == 0)
        {
            return true;
        }
        else if (len == 1)
        {
           for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (word[0] == board[i][j])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        vector<bool> temp;
        for (int i = 0; i < col; i++)
        {
            temp.push_back(false);
        }
        for (int i = 0; i < row; i++)
        {
            isUsed.push_back(temp);
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (word[0] == board[i][j])
                {
                    isUsed[i][j] = true;
                    bool flag = dfs(board, i, j, 1);
                    if (flag)
                    {
                        return true;
                    }
                    isUsed[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, int index)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (_x <= -1 || _x >= row || _y <= -1 || _y >= col)
            {
                continue;
            }
            
            if (isUsed[_x][_y])
            {
                continue;
            }
            
            if (board[_x][_y] == key[index])
            {
                if (index == len - 1)
                {
                    return true;
                }
                isUsed[_x][_y] = true;
                bool flag = dfs(board, _x, _y, index + 1);
                if (flag)
                {
                    return true;
                }
                isUsed[_x][_y] = false;
            }
        }
        return false;
    }
};

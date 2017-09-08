class Solution {
public:
    int row;
    int col;
    
    void gameOfLife(vector<vector<int>>& board) {
        row = board.size();
        if (row == 0) {
            return;
        }
        col = board[0].size();
        if (col == 0) {
            return;
        }
        cal(board, 0);
        refresh(board);
    }
    
    void cal(vector<vector<int>>& board, int i) {
        if (i == row * col) {
            return;
        }
        int r = i / col;
        int c = i % col;
        int s = getRes(board, r - 1, c - 1) + getRes(board, r - 1, c) + getRes(board, r - 1, c + 1) + getRes(board, r, c - 1) + getRes(board, r, c + 1) + getRes(board, r + 1, c - 1) + getRes(board, r + 1, c) + getRes(board, r + 1, c + 1);
        cal(board, i + 1);
        board[r][c] = s + board[r][c] * 10;
    }
    
    void refresh(vector<vector<int>>& board) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                int num = board[r][c];
                if (num >= 10) {
                    if (num == 12 || num == 13) {
                        board[r][c] = 1;
                    } else {
                        board[r][c] = 0;
                    }
                } else {
                    if (num == 3) {
                        board[r][c] = 1;
                    } else {
                        board[r][c] = 0;
                    }
                }
            }
        }
    }
    
    int getRes(vector<vector<int>>& board, int r, int c) {
        if (r < 0 || r > row - 1 || c < 0 || c > col - 1) {
            return 0;
        } else {
            return board[r][c];
        }
    }
    
};

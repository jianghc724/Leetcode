class Solution {
public:
    int row;
    vector<vector<bool>> isUsed;
    vector<vector<string>> res;
    void cal(int r){
        if (r == row)
        {
            vector<string> v_res;
            for (int i = 0; i < row; i++)
            {
                string s;
                for (int j = 0; j < row; j++)
                {
                    if (isUsed[i][j])
                    {
                        s.push_back('.');
                    }
                    else
                    {
                        s.push_back('Q');
                    }
                }
                v_res.push_back(s);
            }
            res.push_back(v_res);
            return;
        }
        
        for (int i = 0; i < row; i++)
        {
            if (!isUsed[r][i])
            {
                vector<pair<int, int>> changed;
				for (int j = 0; j < row; j++)
                {
                    if (!isUsed[r][j] && j != i)
					{
						isUsed[r][j] = true;
						changed.push_back(make_pair(r, j));
					}
                }
                for (int j = r + 1; j < row; j++)
                {
                    if (r + i - j >= 0 && !isUsed[j][r + i - j])
                    {
						isUsed[j][r + i - j] = true;
						changed.push_back(make_pair(j, r + i - j));
                    }
                    if (i + j - r <= row - 1 && !isUsed[j][i + j - r])
                    {
                        isUsed[j][i + j - r] = true;
						changed.push_back(make_pair(j, i + j - r));
                    }
					if (!isUsed[j][i])
					{
						isUsed[j][i] = true;
						changed.push_back(make_pair(j, i));
					}
                }
                cal(r + 1);
				int _len = changed.size();
                for (int j = 0; j < _len; j++)
                {
                    isUsed[changed[j].first][changed[j].second] = false;
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        row = n;
        vector<bool> temp;
        for (int i = 0; i < row; i++)
        {
            temp.push_back(false);
        }
        for (int i = 0; i < row; i++)
        {
            isUsed.push_back(temp);
        }
        cal(0);
        return res;
    }
};

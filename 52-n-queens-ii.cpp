class Solution {
public:
    int res;
    int row;
    vector<vector<bool>> isUsed;
    void cal(int r){
        if (r == row)
        {
            res++;
            return;
        }
        
        for (int i = 0; i < row; i++)
        {
            if (!isUsed[r][i])
            {
                vector<pair<int, int>> changed;
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
    
    
    int totalNQueens(int n) {
        res = 0;
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

class Solution {
public:
    vector<int> maxNumber(vector<int>& num1, vector<int>& num2, int k) {
        if (k <= 0)
        {
            vector<int> res;
            return res;
        }
        int len1 = num1.size();
        int len2 = num2.size();
        int m = 0;
        int n = k;
        if (len2 < k)
        {
            m = k - len2;
        }
        if (len1 < k)
        {
            n = len1;
        }
        vector<int> res(k, 0);
        for (int i = m; i <= n; i++)
        {
            int j = k - i;
            vector<int> a = maxNumberOfK(num1, i);
            vector<int> b = maxNumberOfK(num2, j);
            vector<int> c = combine(a, b);
            if (isBigger(c, res))
            {
                res = c;
            }
        }
        return res;
    }
    
    vector<int> maxNumberOfK(vector<int>& num, int k)
    {
        if (k <= 0)
        {
            vector<int> res;
            return res;
        }
        int len = num.size();
        vector<int> res(k, 0);
        int t = 0;
        int index = len - 1;
        while (t < k)
        {
            res[k - 1 - t] = num[index];
            index--;
            t++;
        }
        for (int i = index; i >= 0; i--)
        {
            if (num[i] > res[0])
            {
                int n = 0;
                while (n < k - 1)
                {
                    if (res[n] < res[n + 1])
                    {
                        break;
                    }
                    n++;
                }
                for (int j = n; j > 0; j--)
                {
                    res[j] = res[j - 1];
                }
                res[0] = num[i];
            }
            else if (num[i] == res[0])
            {
                int j = 1;
                while (j < k)
                {
                    if (num[i] > res[j])
                    {
                        int n = j;
                        while (n < k - 1)
                        {
                            if (res[n] < res[n + 1])
                            {
                                break;
                            }
                            n++;
                        }
                        for (int j = n; j > 0; j--)
                        {
                            res[j] = res[j - 1];
                        }
                        res[0] = num[i];
                        break;
                    }
                    else if (num[i] < res[j])
                    {
                        break;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
        }
        return res;
    }
    
    vector<int> combine(vector<int>& num1, vector<int>& num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();
        int i = 0;
        int j = 0;
        vector<int> res;
        while (i < len1 && j < len2)
        {
            if (num1[i] > num2[j])
            {
                res.push_back(num1[i]);
                i++;
            }
            else if (num1[i] < num2[j])
            {
                res.push_back(num2[j]);
                j++;
            }
            else
            {
                int flag = 0;
                int _i = i;
                int _j = j;
                while (_i < len1 && _j < len2)
                {
                    if (num1[_i] > num2[_j])
                    {
                        flag = 1;
                        break;
                    }
                    else if (num1[_i] < num2[_j])
                    {
                        flag = 2;
                        break;
                    }
                    else
                    {
                        _i++;
                        _j++;
                    }
                }
                if (flag == 0)
                {
                    if (_j == len2)
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 2;
                    }
                }
                if (flag == 1)
                {
                    res.push_back(num1[i]);
                    i++;
                }
                else
                {
                    res.push_back(num2[j]);
                    j++;
                }
            }
        }
        if (i == len1)
        {
            while (j < len2)
            {
                res.push_back(num2[j]);
                j++; 
            }
        }
        else if (j == len2)
        {
            while (i < len1)
            {
                res.push_back(num1[i]);
                i++; 
            }
        }
        return res;
    }
    
    bool isBigger(vector<int>& num1, vector<int>& num2)
    {
        int len = num1.size();
        for (int i = 0; i < len; i++)
        {
            if (num1[i] > num2[i])
            {
                return true;
            }
            else if (num1[i] < num2[i])
            {
                return false;
            }
        }
        return false;
    }
};

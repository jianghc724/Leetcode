class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < len - i; j++)
            {
                dp[j][i + j] = max(dp[j][i + j - 1], dp[j + 1][i + j]);
                if (s[j] == s[i + j])
                {
                    dp[j][i + j] = max(dp[j + 1][i + j - 1] + 2, dp[j][i + j]);
                }
                
            }
        }
        
        return dp[0][len - 1];
    }
};

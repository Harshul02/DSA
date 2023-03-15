int fun(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
    {
        if(ind1 < 0 or ind2 < 0)
        {
            return 0;
        }
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if(s[ind1] == t[ind2])
            return dp[ind1][ind2] = 1 + fun(ind1-1, ind2-1,s , t,dp);
        return dp[ind1][ind2] = max(fun(ind1 - 1, ind2, s, t, dp), fun(ind1, ind2-1, s, t, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return fun(n-1,n-1,s, s1, dp);
        int dp[n+1][n+1];
        for(int i=0; i<=n; i++)
        {
            dp[0][i] = dp[i][0] = 0;
        }

        for(int i= 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(s[i-1] == s1[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
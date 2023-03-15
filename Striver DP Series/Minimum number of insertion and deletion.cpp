#include <bits/stdc++.h> 
int canYouMake(string &str, string &ptr)
{
    int n = str.length();
    int m = ptr.length();
    int dp[n+1][m+1];

    for(int i=0; i<=m; i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j= 1; j<=m; j++)
        {
            if(str[i-1] == ptr[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return n + m - 2*dp[n][m];
}
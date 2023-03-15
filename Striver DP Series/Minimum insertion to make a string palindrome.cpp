#include <bits/stdc++.h> 
int minInsertion(string &str)
{
    // Write your code here.
    int n = str.length();
    string t = str;
    reverse(t.begin(), t.end());
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(str[i-1] == t[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return n - dp[n][n];
}
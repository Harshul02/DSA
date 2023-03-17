#include<bits/stdc++.h>

// Memoization
// Tc = O(n*m)
// SC = O(n*m) + O(n+m)
int fun(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j] != -1)  return dp[i][j];
    if(s[i] == t[j])
        return dp[i][j] = 0 + fun(i-1, j-1, s, t, dp);
    return dp[i][j] = min(1+fun(i-1, j, s, t,dp), min(1+fun(i, j-1, s, t, dp), 1+ fun(i-1, j-1, s,t, dp)));
}

int editDistance(string str1, string str2)
{
    //write you code here
    // int n = str1.length();
    // int m = str2.length();
    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // return fun(n-1, m-1, str1, str2, dp);

//-----------------------------------------------------------
    //Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int i=0; i<=m; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++)
    {
        for(int j =1; j<=m; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 0 + dp[i-1][j-1];
            else dp[i][j] = min(1+dp[i-1][j], min(1+dp[i][j-1], 1+ dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}
#include <bits/stdc++.h> 
int mod = 1e9+7;

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n+m)
int fun(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!= -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = (fun(s1,s2,i-1,j-1, dp) + fun(s1,s2,i-1,j, dp))%mod;
    return dp[i][j] = fun(s1,s2, i-1,j, dp)%mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    // vector<vector<int>> dp(lt, vector<int> (ls, -1));
    // return fun(t,s, lt-1, ls-1, dp);

//-------------------------------------------------------------
    // Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
    int dp[lt+1][ls+1];

    for(int i=0; i<=lt; i++) dp[i][0] = 1;
    for(int i=1; i<=ls; i++) dp[0][i] = 0;

    for(int i = 1; i<=lt; i++)
    {
        for(int j= 1; j<=ls; j++)
        {
            if(t[i-1] == s[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            else
                dp[i][j] = dp[i-1][j]%mod;
        }
    }
    return dp[lt][ls];
} 
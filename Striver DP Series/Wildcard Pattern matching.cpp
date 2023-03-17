#include<bits/stdc++.h>

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n+m)
bool fun(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
   if(i<0 and j<0) return true;
   if(i<0 and j>=0) return false;
   if(j<0 and i>=0){
      for(int k = 0; k<=i; k++)
      {
         if(s1[k] != '*')
            return false;
      }
      return true;
   }
   if(dp[i][j] != -1)
      return dp[i][j];

   if(s1[i] == s2[j] or s1[i] == '?')
      return dp[i][j] = fun(i-1, j-1, s1,s2, dp);
   if(s1[i] == '*')
      return dp[i][j] = fun(i-1, j, s1, s2, dp) or fun(i, j-1, s1, s2, dp);
   return dp[i][j] = false;
}

bool wildcardMatching(string s1, string s2)
{
   // Write your code here.
   // int n = s1.length();
   // int m = s2.length();
   // vector<vector<int>> dp(n, vector<int> (m, -1));
   // return fun(n-1, m-1, s1, s2, dp);

//----------------------------------------------------------
   // Tabulation
   // TC = O(n*m)
   // SC = O(n*m)
   int n = s1.length();
   int m = s2.length();
   vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));

   dp[0][0] = true;
   for(int i=1; i<=m; i++)
   {
      dp[0][i] = false;
   }

   for(int i=1; i<=n; i++)
   {
      bool flag = true;
      for(int j=1; j<=i; j++)
      {
        if (s1[j - 1] != '*') {
          flag = false;
          break;
        }
      }
      dp[i][0] = flag;
   }

   for(int i=1; i<=n; i++)
   {
      for(int j = 1; j<=m; j++)
      {
         if(s1[i-1] == s2[j-1] or s1[i-1] == '?')
            dp[i][j] = dp[i-1][j-1];
         else if(s1[i-1] == '*')
            dp[i][j] = dp[i-1][j] or dp[i][j-1];
         else dp[i][j] = false;
      }
   }
   return dp[n][m];
}
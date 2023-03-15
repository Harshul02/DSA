#include <bits/stdc++.h> 

int lcs(string &str1, string &str2){
	//	Write your code here.
	int n = str1.length();
	int m = str2.length();
	// vector<vector<int>> dp(n+1, vector<int> (m+1));
	int dp[n+1][m+1];

	for(int i=0; i<=m; i++)
	{
		dp[0][i] = 0;
	}
	for(int i=0; i<=n; i++)
	{
		dp[i][0] = 0;
	}
	int maxi = 0;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m ;j++)
		{
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				maxi = max(maxi, dp[i][j]);
			}
			else dp[i][j] = 0;
		}
	}
	return maxi;
}
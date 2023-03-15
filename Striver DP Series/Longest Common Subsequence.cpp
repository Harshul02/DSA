#include<bits/stdc++.h>

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n + m)
int lcs(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
	if(ind1<0 or ind2<0)
		return 0;
	
	if(dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
	if(s[ind1] == t[ind2])
		return dp[ind1][ind2] = 1 + lcs(ind1-1, ind2-1,s ,t, dp);
	return dp[ind1][ind2] = max(lcs(ind1-1, ind2, s, t, dp), lcs(ind1, ind2-1, s, t, dp));
}

int lcs(string s, string t)
{
	//Write your code here
	// int n = s.length();
	// int m = t.length();
	// vector<vector<int>> dp(n, vector<int> (m, -1));
	// return lcs(n-1,m-1,s,t,dp);

//-------------------------------------------------------------
    // Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
	int n = s.length();
	int m = t.length();
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	for(int i = 0; i<=m; i++)
	{
		dp[0][i] = 0;
	}
	for(int i=0; i<=n; i++)
	{
		dp[i][0] = 0;
	}

	for(int ind1 = 1; ind1<=n; ind1++)
	{
		for(int ind2 = 1; ind2<=m; ind2++)
		{
			if(s[ind1-1] == t[ind2-1])
				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
			else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
		}
	}
	return dp[n][m];
}
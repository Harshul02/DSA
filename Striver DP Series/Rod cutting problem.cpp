#include<bits/stdc++.h>

// Memoization
// Tc = O(n*m)
// SC = O(n*m) + O(n)
int fun(int ind, vector<int> price, int n, vector<vector<int>> &dp)
{
	if(ind == 0)
		return n * price[0];
	
	if(dp[ind][n] != -1)
		return dp[ind][n];
	int not_take = fun(ind-1, price, n, dp);
	int take = INT_MIN;
	int rodLength = ind + 1;
	if(rodLength <= n) take = price[ind] + fun(ind, price, n- rodLength, dp);

	return dp[ind][n] = max(take, not_take);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	// vector<vector<int>> dp(n, vector<int> (n+1, -1));
	// return fun(n-1, price, n, dp);

// ------------------------------------------------------------------
    // Tabulation
    // TC = O(n*m)
    // SC = o(n*m)
	vector<vector<int>> dp(n, vector<int> (n+1, 0));
	for(int i=0; i<=n; i++)
	{
		dp[0][i] = i*price[0];
	}

	for(int ind = 1; ind<n; ind++)
	{
		for(int len = 0; len <= n; len++)
		{
			int not_take = dp[ind-1][len];
			int take = INT_MIN;
			int rodLength = ind + 1;
			if(rodLength <= len) take = price[ind] + dp[ind][len - rodLength];

			dp[ind][len] = max(take, not_take);
		}
	}
	return dp[n-1][n];

}

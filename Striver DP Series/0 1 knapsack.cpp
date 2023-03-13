#include <bits/stdc++.h> 

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n)
int fun(int ind, int w, vector<int> wt, vector<int> val,vector<vector<int>> &dp)
{
	if(ind == 0)
	{
		if(wt[0] <= w)	return val[0];
		else return 0;
	}
	if(dp[ind][w] != -1)
		return dp[ind][w];

	int not_take = 0 + fun(ind-1, w, wt, val,dp);
	int take = INT_MIN;
	if(wt[ind] <= w)
		take = val[ind] + fun(ind-1, w-wt[ind], wt, val,dp);
	return dp[ind][w] = max(take, not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	// return fun(n-1, maxWeight, weight, value, dp);

    //------------------------------------------------------------------------------
    // Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
    
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

	for(int i=weight[0]; i<=maxWeight; i++)
		dp[0][i] = value[0];

	for(int ind = 1; ind<n; ind++)
	{
		for(int w = 0; w<=maxWeight; w++)
		{
			int not_take = 0 + dp[ind-1][w];
			int take = INT_MIN;
			if(weight[ind] <= w)
				take = value[ind] + dp[ind-1][w-weight[ind]];
			dp[ind][w] = max(take, not_take);
		}
	}
	return dp[n-1][maxWeight];
}
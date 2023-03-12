#include <bits/stdc++.h> 

//Memoization

// TC - O(n*n)
// SC - O(n*n)
int fun(int i, int j, vector<vector<int>>& a, int n, vector<vector<int>> dp)
{
	if(i == n-1)return a[i][j];

	if(dp[i][j] != -1)
		return dp[i][j];
	int d = a[i][j] + fun(i+1,j,a,n, dp);
	int dg = a[i][j] + fun(i+1,j+1, a, n, dp);
	return dp[i][j] = min(d,dg);
}



int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	// vector<vector<int>> dp(n, vector<int> (n,-1));
	// return fun(0,0, triangle, n, dp);
//-------------------------------------------------------------------

    // Tabulation
    //TC - O(n*n)
    //SC -  O(n*n)

	int dp[n][n];
	for(int j=0; j<n; j++)
	{
		dp[n-1][j] = triangle[n-1][j];
	}
	for(int i=n-2; i>=0; i--)
	{
		for(int j=i; j>=0; j--)
		{
			int d = triangle[i][j] + dp[i+1][j];
			int dg = triangle[i][j] + dp[i+1][j+1];
			dp[i][j] = min(d,dg);
		}
	}
	return dp[0][0];
}
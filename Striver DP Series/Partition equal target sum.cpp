#include<bits/stdc++.h>

//Memoization
// TC = O(n*target)
// SC = O(n*target) + O(n)
bool fun(vector<int> &a, int i, int target, vector<vector<int>> &dp)
{
	if(target == 0) return true;
	if(i == 0) return a[0] == target;
	if(dp[i][target] != -1)
		return dp[i][target];
	bool not_take = fun(a, i-1, target, dp);
	bool take = false;
	if(target >= a[i])
		take = fun(a, i-1, target - a[i], dp);
	return dp[i][target] = take | not_take;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	// int sum = accumulate(arr.begin(), arr.end(), 0);
	// vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
	// if(sum%2)
	// 	return false;
	// return fun(arr, n-1, sum/2,dp);

    //-------------------------------------------------------------------------
    //Tabulation
    // TC = O(n*target)
    // SC = O(n*target)
	int sum = accumulate(arr.begin(), arr.end(), 0);
	vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0));
	if(sum%2)
		return false;
	
	for(int i=0; i<n; i++)
	{
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;

	for(int i = 1; i<n; i++)
	{
		for(int target = 1; target <= sum/2; target++)
		{
			bool not_take = dp[i-1][target];
			bool take = false;
			if(target >= arr[i])
				take = dp[i-1][target - arr[i]];
			dp[i][target] = take | not_take;
		}
	}
	return dp[n-1][sum/2];
}

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = accumulate(arr.begin(), arr.end(), 0);

	vector<vector<bool>> dp(n+1, vector<bool> (sum, 0));

	for(int i=0; i<n; i++)
	{
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;

	for(int i= 1; i<n; i++)
	{
		for(int target = 1; target <=sum; target++)
		{
			bool not_take = dp[i-1][target];
			bool take = false;
			if(target >= arr[i])
				take = dp[i-1][target-arr[i]];
			dp[i][target] = take | not_take;
		}
	}

	int mini = 1e9;
	for(int i=0; i<=sum/2; i++)
	{
		if(dp[n-1][i] == true)
		{
			mini = min(mini, abs(sum-i-i));
		}
	}
	return mini;
}

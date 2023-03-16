#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int n = a.length();
	int m = b.length();

	int dp[n+1][m+1];
	for(int i=0; i<=m; i++)	dp[0][i] = 0;
	for(int i=0; i<=n; i++)	dp[i][0] = 0;

	for(int i=1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int i = n, j=m;
	string ans = "";
	while(i>0 and j>0)
	{
		if(a[i-1] == b[j-1]){
			ans += a[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
		{
			ans += a[i-1];
			i--;
		}
		else{
			ans+=b[j-1];
			j--;
		}
	}
	while(i>0){ans+= a[i-1]; i--;}
	while(j>0){ans+= b[j-1]; j--;}
	reverse(ans.begin(), ans.end());
	return ans;
}
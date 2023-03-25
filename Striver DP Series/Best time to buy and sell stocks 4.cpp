#include <bits/stdc++.h> 

// Tabulation
// TC = O(n*2*k)
// SC = O(n*2*k)

int maximumProfit(vector<int> &a, int n, int k)
{
    // Write your code here.
   vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
    

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            for(int cap = 1; cap<=k; cap++)
            {
                if(buy == 1)
                {
                    dp[ind][buy][cap] = max(-a[ind] + dp[ind + 1][0][cap], 0 + dp[ind+1][1][cap]);
                }
                else
                dp[ind][buy][cap] = max(a[ind] + dp[ind + 1][1][cap-1], 0 + dp[ind+1][0][cap]);
}
        }
    }
    return dp[0][1][k];
}
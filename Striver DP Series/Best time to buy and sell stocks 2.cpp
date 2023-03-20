#include<bits/stdc++.h>

// Memoization
// TC = O(n*2)
// SC = O(n*2) + O(n)
long fun(int ind, int buy, long a[], int n, long &profit, vector<vector<long>> &dp)
{
    if(ind == n)
        return 0;
    
    if(dp[ind][buy] != -1)
        return dp[ind][buy];
    if(buy)
    {
        profit = max(-a[ind] + fun(ind+1, 0, a, n, profit,dp), 0 + fun(ind+1, 1, a, n, profit, dp));
    }
    else
    {
        profit = max(a[ind] + fun(ind+1, 1, a, n, profit, dp), 0 + fun(ind+1, 0, a, n, profit, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *a, int n)
{
    //Write your code here
    // long profit = 0;
    // vector<vector<long>> dp(n, vector<long> (2,-1));
    // return fun(0, 1, a, n, profit, dp);
//---------------------------------------------------------------------------------------

    // Tabulation
    // TC = O(n*2)
    // SC = O(n*2)
    long profit = 0;
    vector<vector<long>> dp(n+1, vector<long> (2,0));

    dp[n][0] = dp[n][1] = 0;
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            if(buy)
            {
                profit = max(-a[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else
            {
                profit = max(a[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
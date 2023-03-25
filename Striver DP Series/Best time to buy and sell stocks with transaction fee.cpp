#include <bits/stdc++.h> 

// Memoization
// TC = O(n*2)
// SC = O(n*2) + O(n)
int fun(int ind, int buy, vector<int> a, int n, int fee, vector<vector<int>> &dp)
{
    if(ind == n)
        return 0;
    
    if(dp[ind][buy]!= -1)
        return dp[ind][buy];
    if(buy){
        return dp[ind][buy] = max(-a[ind] + fun(ind+1, 0, a, n, fee, dp), 0 + fun(ind+1, 1, a, n, fee, dp));
    }
    return dp[ind][buy] = max(a[ind] + fun(ind+1, 1, a, n, fee, dp) - fee, 0 + fun(ind+1, 0, a, n, fee, dp));
}

int maximumProfit(int n, int fee, vector<int> &a) {
    // Write your code here.
    // vector<vector<int>> dp(n, vector<int> (2, -1));
    // return fun(0, 1, a, n, fee, dp);

//--------------------------------------------------------------------------------------
    // Tabulation
    // TC = O(n*2)
    // SC = O(n*2)
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int ind= n-1; ind>=0; ind--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            if(buy){
                dp[ind][buy] = max(-a[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else
                dp[ind][buy] = max(a[ind] + dp[ind+1][1] - fee, 0 + dp[ind+1][0]);
        }
    }
    return dp[0][1];
}
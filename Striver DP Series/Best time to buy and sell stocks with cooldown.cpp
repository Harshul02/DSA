#include <bits/stdc++.h> 


// Memoization
// TC = O(n*2)
// SC = O(n*2) + O(n)
int fun(int ind, int buy, vector<int> a, int n, vector<vector<int>> &dp)
{
    if(ind >= n) return 0;

    if(dp[ind][buy] != -1)
        return dp[ind][buy];
    if(buy)
    {
        return dp[ind][buy] = max(-a[ind] + fun(ind+1, 0, a, n, dp), 0 + fun(ind+1, 1, a, n, dp));
    }
    return dp[ind][buy] = max(a[ind] + fun(ind+2, 1, a, n, dp), 0 + fun(ind+1, 0, a, n, dp));
}

int stockProfit(vector<int> &a){
    // Write your code here.
    // int n = prices.size();
    // vector<vector<int>> dp(n, vector<int> (2, -1));
    // return fun(0, 1, prices, n, dp);
//-----------------------------------------------------------------------

    // Tabulation
    // TC = O(n*2)
    // SC = O(n*2)
    int n = a.size();
    vector<vector<int>> dp(n+2, vector<int> (2, 0));

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int buy = 0; buy <=1; buy++)
        {
            if(buy)
            {
                dp[ind][buy] = max(-a[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            } 
            else {
              dp[ind][buy] = max(a[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}
#include <bits/stdc++.h> 

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n)
int fun(int ind, int w, vector<int> pro, vector<int> wt, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        return (w/wt[ind])*pro[ind];
    }
    if(dp[ind][w] != -1)
        return dp[ind][w];

    int not_take = 0 + fun(ind-1, w, pro, wt, dp);
    int take = INT_MIN;
    if(wt[ind]<=w) take = pro[ind] + fun(ind, w - wt[ind], pro, wt, dp);

    return dp[ind][w] = max(take, not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // vector<vector<int>> dp(n, vector<int> (w+1, -1));
    // return fun(n-1, w, profit, weight,dp);
// ---------------------------------------------------------------------

    // Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
    vector<vector<int>> dp(n, vector<int> (w+1, 0));

    for(int i=0; i<= w; i++)
    {
        dp[0][i] = ((int)(i/weight[0]))*profit[0];
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int va = 0; va<=w; va++)
        {
            int not_take = 0 + dp[ind-1][va];
            int take = 0;
            if(weight[ind]<=va) take = profit[ind] + dp[ind][va - weight[ind]];

            dp[ind][va] = max(take, not_take);
        }
    }
    return dp[n-1][w];
}

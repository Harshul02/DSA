#include <bits/stdc++.h> 


//Memoization
// TC = O(n*target)
// SC = O(n*target) + O(n)
bool fun(int ind, int target, vector<int> &a, vector<vector<int>> &dp)
{
    if(target == 0) return true;
    if(ind == 0) return (a[0] == target);

    if(dp[ind][target] != -1)
        return dp[ind][target];

    bool not_take = fun(ind-1, target,a,dp);
    bool take = false;
    if(target >= a[ind])
        take = fun(ind - 1, target - a[ind], a,dp);
    
    return dp[ind][target] = (take) | (not_take);
}

bool subsetSumToK(int n, int k, vector<int> &a) {
    // Write your code here.
    // vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    // return fun(n-1,k,a,dp);

    //------------------------------------------------------------------
    //Tabulation
    // TC = O(n*target)
    // SC = O(n*target)
    vector<vector<bool>> dp(n+1, vector<bool> (k+1, 0));

    for(int i=0; i<n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][a[0]] = true;

    for(int i=1; i<n; i++)
    {
        for(int target = 1; target <= k; target++)
        {
            bool not_take = dp[i-1][target];
            bool take = false;
            if(target >= a[i])
                take = dp[i - 1][target - a[i]];
    
            dp[i][target] = (take) | (not_take);
        }
    }
    return dp[n-1][k];

}
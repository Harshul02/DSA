#include<bits/stdc++.h>

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n)
long fun(int ind, int a[], int val, vector<vector<long>> &dp)
{
    if(ind == 0)
    {
        if(val % a[ind] == 0) return 1;
        return 0;
    }
    if(dp[ind][val] != -1)
        return dp[ind][val];

    long not_take = fun(ind-1, a, val, dp);
    long take = 0;
    if(a[ind]<=val) take = fun(ind, a, val-a[ind], dp);
    return dp[ind][val] = take + not_take;
}

long countWaysToMakeChange(int *den, int n, int value)
{
    //Write your code here
    // vector<vector<long>> dp(n, vector<long> (value+1, -1));
    // return fun(n-1, den, value,dp);

    //-----------------------------------------------------------------------
    // Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
    vector<vector<long>> dp(n, vector<long> (value+1, 0));

    for(int i=0; i<=value; i++)
    {
        if(i % den[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }

    for(long ind = 1; ind<n; ind++)
    {
        for(long val = 0;val<= value; val++)
        {
            long not_take = dp[ind-1][val];
            long take = 0;
            if(den[ind]<=val) take = dp[ind][val-den[ind]];
            dp[ind][val] = take + not_take;
        }
    }
    return dp[n-1][value];

}
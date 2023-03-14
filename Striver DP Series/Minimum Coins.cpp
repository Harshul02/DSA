#include <bits/stdc++.h> 

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n)
int fun(int ind, vector<int> a, int x, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(x%a[ind] == 0)   return x/a[ind];
        else return 1e9;
    }
    if(dp[ind][x] != -1)
        return dp[ind][x];

    int not_take = fun(ind - 1, a, x, dp);
    int take = INT_MAX;
    if(a[ind]<=x) take = 1 + fun(ind, a, x - a[ind], dp);
    return dp[ind][x] = min(take, not_take);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // int n = num.size();
    // vector<vector<int>> dp(n, vector<int> (x+1, -1));
    // int cnt = fun(n-1, num, x, dp);
    // if(cnt > 1e8)   return -1;
    // return cnt;

    //------------------------------------------------------------------
    // Tabulation
    // TC = O(n*m)
    // SC = O(n*m)
    
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (x+1, 0));

    for(int i=0; i<=x; i++)
    {
        if(i%num[0] == 0) dp[0][i] = i/num[0];
        else
        dp[0][i] = 1e9;
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int tar = 0; tar<=x; tar++){
            int not_take = dp[ind - 1][tar];
            int take = INT_MAX;
            if(num[ind]<=tar) take = 1 + dp[ind][tar - num[ind]];
            dp[ind][tar] = min(take, not_take);
        }
    }
    int ans = dp[n-1][x];
    if(ans > 1e8)   return -1;
    return ans;

}
#include <bits/stdc++.h> 

// Memoization
// TC = O(n*2*3)
// SC = O(n*2*3) + O(n)
int fun(int ind, int buy, int cap, vector<int> a, int n, vector<vector<vector<int>>> &dp)
{
    if(cap == 0) return 0;
    if(ind == n) return 0;

    if(dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    if(buy)
    {
        return dp[ind][buy][cap] = max(-a[ind] + fun(ind + 1, 0, cap, a, n, dp), 0 + fun(ind+1, 1, cap, a, n, dp));
    }
    return dp[ind][buy][cap] = max(a[ind] + fun(ind + 1, 1, cap-1, a, n, dp), 0 + fun(ind+1, 0, cap, a, n, dp));
}

int maxProfit(vector<int>& a, int n)
{
    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    // return fun(0, 1, 2, a, n, dp);
//--------------------------------------------------------------------------------------------

    // Tabulation
    // TC = O(n*2*3)
    // SC = O(n*2*3)
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            for(int cap = 1; cap<=2; cap++)
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
    return dp[0][1][2];
}






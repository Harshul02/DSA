#include <bits/stdc++.h> 

// TC = O(N)
// SC = O(N) + O(N);
int jump(int ind, vector<int> &heights, vector<int> &dp)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1)
        return dp[ind];
    int left = jump(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind>1)
        right = jump(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);

    return dp[ind] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int> dp(n+1, -1);
    // return jump(n-1, heights, dp);
    // --------------------------------------------------------------------

    //Tabulation
    // TC = O(N)
    // SC = O(N)

    // int dp[n] = {0};
    // dp[0] = 0;

    // for(int i=1; i<n; i++)
    // {
    //     int left = dp[i-1] + abs(heights[i] - heights[i-1]);
    //     int right = INT_MAX;
    //     if(i>1)
    //     {
    //         right = dp[i-2] + abs(heights[i] - heights[i-2]);
    //     }
    //     dp[i] = min(left,right);
    // }
    // return dp[n-1];


    //Space Optimization
    // TC = O(N)
    // SC = O(1)

    int prev = 0;
    int prev1 = 0;
    for(int i=1; i<n; i++)
    {
        int left = prev + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = prev1 + abs(heights[i] - heights[i-2]);
        
        int curr = min(left,right);
        prev1 = prev;
        prev = curr;
    }
    return prev;

}
#include <bits/stdc++.h>

int fun(int ind, int sum, vector<int> a, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(sum == 0 && a[0] == 0) return 2;
        if(sum == 0 or sum == a[ind]) return 1;
        return 0;
    }

    if(dp[ind][sum] != -1)
        return dp[ind][sum];
    
    int not_take = fun(ind - 1, sum, a, dp);
    int take = 0;
    if(a[ind] <= sum) take = fun(ind-1, sum - a[ind], a, dp);

    return dp[ind][sum] = take + not_take;

}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if(sum - target < 0 || (sum - target)%2) return 0;

    vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    return fun(n-1, (sum-target)/2, arr, dp);
}

#include <bits/stdc++.h> 
int mod = 1e9 + 7;

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n)
int fun(int ind, vector<int> a, int target, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(target == 0 && a[0] == 0) return 2;
        if(target == 0 or target == a[ind]) return 1;
        return 0;
    }
    if(dp[ind][target] != -1)
        return dp[ind][target];
    int not_take = fun(ind-1, a, target, dp);
    int take = 0;
    if(target >= a[ind]) take = fun(ind - 1, a, target - a[ind], dp);

    return dp[ind][target] = (take + not_take)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    if(sum - d <0 || (sum-d)%2 == 1)
        return 0;
    
    return fun(n-1, arr, (sum-d)/2, dp);
}



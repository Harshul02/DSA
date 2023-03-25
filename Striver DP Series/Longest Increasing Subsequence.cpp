#include<bits/stdc++.h>

// Memoization
// TC = O(n*n)
// SC = O(n*n) * O(n)
int fun(int ind,int prev_ind, int a[], int n, vector<vector<int>> &dp)
{
    if(ind == n)
        return 0;
    
    if(dp[ind][prev_ind+1] != -1)
        return dp[ind][prev_ind+1];

    int len = 0 + fun(ind+1,prev_ind, a, n, dp);
    if(prev_ind == -1 or a[ind]>a[prev_ind])
        len = max(len, 1 + fun(ind+1, ind, a, n, dp));
    return dp[ind][prev_ind+1] = len;

}

int longestIncreasingSubsequence(int a[], int n)
{
    // Write Your Code here
    // vector<vector<int>> dp(n, vector<int> (n+1, -1));
    // return fun(0,-1, arr, n, dp);
//-------------------------------------------------------------------------------
    // Tabulation
    // TC = O(n*n)
    // SC = O(n*n)
    // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    // vector<int> next(n+1, 0), curr(n+1, 0);
    // for(int ind = n-1; ind>=0; ind--)
    // {
    //     for(int prev_ind = ind-1; prev_ind >=-1; prev_ind--)
    //     {
    //         int len = 0 + next[prev_ind+1];
    //         if(prev_ind == -1 or a[ind]>a[prev_ind])
    //             len = max(len, 1 + next[ind+1]);
    //         curr[prev_ind+1] = len;
    //     }
    //     next = curr;
    // }
    // return next[0];


    // Printing the Longest Increasing Subsequence
    // vector<int> dp(n, 1), hash(n);
    // int maxi = 1;
    // int lastInd = 0;
    // for(int i=0; i<n; i++)
    // {
    //     hash[i] = i;
    //     for(int j = 0; j<i; j++)
    //     {
    //       if (a[j] < a[i] and 1 + dp[j] > dp[i]) {
    //         dp[i] = 1 + dp[j];
    //         hash[i] = j;
    //       }
    //     }
    //     if(dp[i] > maxi)
    //     {
    //         maxi = dp[i];
    //         lastInd = i;
    //     }
    // }

    // vector<int> temp;
    // temp.push_back(a[lastInd]);
    // while(hash[lastInd] != lastInd)
    // {
    //     lastInd = hash[lastInd];
    //     temp.push_back(a[lastInd]);
    // }
    // reverse(temp.begin(), temp.end());
    // for(auto it : temp)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // return maxi;


    // Binary Search Approach

    vector<int> temp;
    temp.push_back(a[0]);
    int len = 1;
    for(int i = 1; i<n; i++)
    {
        if(a[i] > temp.back()){
            temp.push_back(a[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
            temp[ind] = a[i];
        }
    }
    return len;
}

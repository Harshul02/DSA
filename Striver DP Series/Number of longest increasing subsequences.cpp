#include <bits/stdc++.h> 

// TC = O(N*N)
int findNumberOfLIS(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    int maxi = 1;

    vector<int> dp(n, 1), cnt(n,1);
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(a[i] > a[j] and dp[j] +1> dp[i])
            {
                dp[i] = 1+dp[j];
                cnt[i] = cnt[j];
            }
            else if(a[j] < a[i] and 1 + dp[j] == dp[i])
            {
                cnt[i] += cnt[j];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int nos = 0;
    for(int i = 0;i <n; i++)
    {
        if(dp[i] == maxi) nos+=cnt[i];
    }
    return nos;
}
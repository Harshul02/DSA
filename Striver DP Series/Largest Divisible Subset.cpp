#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &a){
    // Write your code here.
    int n = a.size();
    int maxi = 1;
    int lastInd = 0;
    vector<int> dp(n, 1), hash(n);
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++)
    {
        hash[i] = i;
        for(int j = 0; j<i; j++)
        {
            if(a[i]%a[j] == 0 and dp[i] < 1+dp[j])
            {
                dp[i] = 1+ dp[j];
                hash[i] = j;
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            lastInd = i;
        }
    }

    // Backtracking
    vector<int> temp;
    temp.push_back(a[lastInd]);
    while(hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        temp.push_back(a[lastInd]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
#include <bits/stdc++.h> 

bool checkPossible(string &s1, string &s2)
{
    if(s1.size() != s2.size() + 1)  return false;

    int first = 0;
    int second = 0;

    while(first < s1.size())
    {
        if(s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first == s1.size() and second == s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2) { return s1.size() < s2.size(); }

int longestStrChain(vector<string> &a)
{
    // Write your code here.
    int n = a.size();
    vector<int> dp(n, 1);
    sort(a.begin(), a.end(), comp);
    int maxi = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(checkPossible(a[i], a[j]) and 1 + dp[j] > dp[i])
            {
                dp[i] = dp[j] +1;
            }
            maxi = max(maxi, dp[i]);
        }
    }
    return maxi;
}
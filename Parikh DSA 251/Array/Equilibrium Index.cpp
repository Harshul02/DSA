#include <bits/stdc++.h> 
int findEquilibriumIndex(vector<int> &arr) {
    // Write your code here.
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(cnt == sum - cnt - arr[i])
            return i;
        cnt += arr[i];
    }
    return -1;
}
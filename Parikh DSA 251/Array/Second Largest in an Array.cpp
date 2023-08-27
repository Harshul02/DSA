#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    if(n == 1)
        return -1;
    int max1 = arr[0], max2 = INT_MIN;
    for(int i = 1; i<n; i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] < max1 and arr[i] > max2){
            max2 = arr[i];
        }
    }
    if(max2 != INT_MIN)
        return max2;
    return -1;
}
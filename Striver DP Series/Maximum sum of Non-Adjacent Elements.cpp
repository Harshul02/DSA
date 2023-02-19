#include <bits/stdc++.h> 

// TC = O(N)
// SC = O(N) + O(N)

// int fib(int n, vector<int> &nums, vector<int> &dp)
// {
//     if(n == 0) return nums[n];
//     if(n <0) return 0;
//     if(dp[n] != -1)
//         return dp[n];
    
//     int pick = nums[n] + fib(n-2, nums, dp);
//     int notpick = 0 + fib(n-1, nums, dp);
//     return dp[n] = max(pick,notpick);
    
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return fib(nums.size()-1, nums, dp);
// }

//----------------------------------------------------------------------------------------------------------------

//Optimized Code
// TC = O(N)
// SC = O(1)

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1; i<n; i++)
    {
        int take = nums[i];
        if(i>1)
            take += prev2;
        int notTake = 0 + prev;

        int curr = max(take, notTake);
        prev2=prev;
        prev = curr;
    }
    return prev;
}
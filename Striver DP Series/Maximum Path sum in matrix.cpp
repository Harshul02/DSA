#include <bits/stdc++.h> 


//Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n)

int fun(vector<vector<int>> &a, int n, int m, int i, int j, vector<vector<int>> &dp)
{
    if((j<0 || j>=m))
        return -1e9;
    if(i == 0)
        return a[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int d = a[i][j] + fun(a, n,m, i-1, j,dp);
    int dld = a[i][j] + fun(a, n,m, i-1, j-1,dp);
    int drd = a[i][j] + fun(a, n,m, i-1, j+1,dp);
    return dp[i][j] = max(d,max(dld,drd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    // vector<vector<int>> dp(n, vector<int> (m,-1));
    // int maxi = INT_MIN;
    // for(int i=0; i<m; i++)
    // {
    //     maxi = max(maxi, fun(matrix,n,m, n-1, i, dp));
    // }
    // return maxi;

    //---------------------------------------------------------------------
    // Tabulation
    // TC = O(n*m) + O(m)
    // SC = O(n*m)
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;

}
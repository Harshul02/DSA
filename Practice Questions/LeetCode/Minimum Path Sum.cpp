class Solution {
public:

    int fun(int i, int j, vector<vector<int>> grid, vector<vector<int>> &dp)
    {
        if(i == 0 and j == 0) return grid[0][0];
        if(i<0 or j<0) return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = grid[i][j], left = grid[i][j];
        if(i>0) up += fun(i-1, j, grid, dp);
        else up += 1e9;
        if(j>0) left += fun(i, j-1, grid, dp);
        else left += 1e9;
        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return fun(m-1, n-1, grid, dp);
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i==0 and j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left += 1e9;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
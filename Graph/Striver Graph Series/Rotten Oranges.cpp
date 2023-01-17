int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        int ans[n][m];
        int time=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    ans[i][j] = 2;
                }
                else{
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int ntime = q.front().second;
            q.pop();
            time = max(time, ntime);
            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && grid[nrow][ncol] == 1 && ans[nrow][ncol] != 2)
                {
                    ans[nrow][ncol] = 2;
                    q.push({{nrow,ncol},ntime+1});
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(ans[i][j] !=2 && grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
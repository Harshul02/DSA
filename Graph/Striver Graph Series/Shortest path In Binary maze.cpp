int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        queue<pair<int, pair<int,int>>> q;
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] != 0)
                {
                    if(dis + 1 < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = dis+1;
                        q.push({dis+1, {nrow,ncol}});
                    }
                }
            }
        }
        
        if(dist[destination.first][destination.second] == 1e9) return -1;
        
        return dist[destination.first][destination.second];
    }
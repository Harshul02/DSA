int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        q.push({0,{0,0}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            
            if(row == n-1 and col == m-1) return diff;
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        q.push({newEffort, {nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
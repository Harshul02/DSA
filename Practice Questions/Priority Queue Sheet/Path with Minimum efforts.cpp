int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 and col == m-1)
                return diff;

            for(int i=0; i<4; i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >=0 and nrow <n and ncol >=0 and ncol <m){
                    int newDis = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(newDis < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newDis;
                        pq.push({newDis, {nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
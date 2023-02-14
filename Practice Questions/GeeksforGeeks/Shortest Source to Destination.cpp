int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0)
            return -1;
        vector<vector<int>> vis(N, vector<int> (M,0));
        int level = 0;
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vis[0][0] = 1;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second.first;
            level = q.front().second.second;
            q.pop();
            if(row == X and col == Y)
            {
                return level;
            }
            for(int i=0; i<4; i++)
            {
                int delr = row + dr[i];
                int delc = col + dc[i];
                if(delr>=0 and delr<N and delc>=0 and delc<M and vis[delr][delc] == 0 and A[delr][delc]==1)
                {
                    vis[delr][delc] = 1;
                    q.push({delr, {delc, level+1}});
                }
            }
        }
        return -1;
    }
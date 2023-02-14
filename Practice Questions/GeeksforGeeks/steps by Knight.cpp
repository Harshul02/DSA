int minStepToReachTarget(vector<int>&knightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> vis(N, vector<int> (N,0));
	    queue<pair<int, pair<int,int>>> q;
	    int dr[] = {1,2,2,1,-1,-2,-2,-1};
	    int dc[] = {2,1,-1,-2,-2,-1,1,2};
	    int level = 0;
	    q.push({knightPos[0]-1, {knightPos[1]-1,level}});
	    vis[knightPos[0]-1][knightPos[1]-1] =1;
	    while(!q.empty())
	    {
	        int row = q.front().first;
	        int col = q.front().second.first;
	        int level = q.front().second.second;
	        q.pop();
	        
	        if(row == TargetPos[0]-1 and col == TargetPos[1] -1)
	        {
	            return level;
	        }
	        for(int i=0; i<8; i++)
	        {
	            int delr = row + dr[i];
	            int delc = col + dc[i];
	            if(delr>=0 and delr<N and delc>=0 and delc<N and vis[delr][delc]==0)
	            {
	                vis[delr][delc] =1;
	                q.push({delr, {delc,level+1}});
	            }
	        }
	    }
	    return -1;
	}
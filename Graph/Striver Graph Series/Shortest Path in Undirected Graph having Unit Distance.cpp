vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0; i<M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int vis[N] = {0};
        queue<pair<int,int>> q;
        q.push({src,0});
        
        vector<int> dist(N);
        for(int i=0; i<N; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();
            
            for(auto it: adj[node])
            {
                if(dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push({it, dist[it]});
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
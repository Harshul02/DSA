int timer = 1;
  
  void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tim[], int low[], vector<int> &mark)
  {
    vis[node] = 1;
    tim[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it: adj[node])
    {
        if(it == parent) continue;
        
        if(!vis[it])
        {
            dfs(it, node, vis, adj, tim, low, mark);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tim[node] and parent!= -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], tim[it]);
        }
    }
    if(child > 1 and parent == -1)
        mark[node] = 1;
  }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n, 0);
        int tim[n];
        int low[n];
        vector<int> mark(n,0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, vis, adj, tim, low, mark);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
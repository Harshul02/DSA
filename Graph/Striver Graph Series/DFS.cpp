void dfs(int node, vector<int> adj[], int vis[], vector<int> &v)
    {
        vis[node] = 1;
        v.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis, v);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> v;
        dfs(start, adj, vis, v);
        return v;
    }
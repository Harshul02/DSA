void dfs(int node, vector<int> ad[], int vis[])
    {
        vis[node] = 1;
        for(auto it: ad[node])
        {
            if(!vis[it])
            {
                dfs(it, ad, vis);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> ad[V];
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(adj[i][j] == 1 && i!=j)
                {
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int c=0;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i, ad, vis);
            }
        }
        return c;
    }
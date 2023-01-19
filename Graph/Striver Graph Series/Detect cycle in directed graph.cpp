bool dfsCheck(int start, vector<int> adj[], int vis[], int pathvis[])
    {
        vis[start] = 1;
        pathvis[start] = 1;
        
        for(auto it: adj[start])
        {
            if(!vis[it])
            {
                if(dfsCheck(it, adj, vis, pathvis))
                    return true;
            }
            else if(pathvis[it])
                return true;
        }
        
        pathvis[start] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathvis[V]  = {0};
        
        for(int i=0; i <V; i++)
        {
          if(!vis[i])
          {
              if(dfsCheck(i, adj, vis, pathvis))
                return true;
          }
        }
        return false;
    }
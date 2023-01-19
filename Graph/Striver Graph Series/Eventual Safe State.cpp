bool dfs(int start, vector<int> adj[], int vis[], int pathvis[], int check[])
   {
       vis[start] = 1;
       pathvis[start] = 1;
       check[start] = 0;
       
       
       for(auto it: adj[start])
       {
           if(!vis[it])
           {
               if(dfs(it, adj, vis, pathvis, check))
               {
                   check[it] = 0;
                   return true;
               }
           }
           else if(pathvis[it])
           {
               check[it] = 0;
               return true;
           }
       }
       
       pathvis[start] = 0;
       check[start] = 1;
       return false;
   }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        int check[V] = {0};
        vector<int> safenodes;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,pathvis, check);
            }
        }
        for(int i=0; i<V; i++)
        {
            if(check[i] ==1 )
            {
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
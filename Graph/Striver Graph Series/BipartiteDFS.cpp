bool dfs(int start,int col, int V, vector<int> adj[], int color[])
    {
        color[start] = col;
        
        for(auto it: adj[start])
        {
            if(color[it] == -1)
            {
                if(dfs(it, !col, V, adj, color) == false) return false;
            }
            else if(color[it] == col)
            {
                return false;
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	 int color[V];
	    for(int i=0; i<V; i++)
	        color[i] = -1;  
	        
	        for(int i=0; i<V; i++)
	        {
	            if(color[i] == -1){
	            if(dfs(i, 0,V,adj,color) == false)
	                return false;
	            }
	        }
	        return true;
	}
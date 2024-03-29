void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
	{
	    vis[node] = 1;
	    
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it, vis, adj, st);
	        }
	    }
	    st.push(node);
	}
	void dfsT(int node, vector<int> &vis, vector<int> adj[])
	{
	    vis[node] = 1;
	    
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfsT(it, vis, adj);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0; i<V; i++)
        {
            vis[i] = 0;
            for(auto it: adj[i])
            {
                //before it is i->it
                //after reverse, it should be it->i
                adjT[it].push_back(i);
            }
        }
        
        int cnt=0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(vis[node] == 0)
            {
                cnt++;
                dfsT(node, vis, adjT);
            }
        }
        return cnt;
    }
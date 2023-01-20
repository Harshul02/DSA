void dfs(int start, stack<int> &st, int vis[], vector<int> adj[])
	{
	    vis[start] = 1;
	    for(auto it: adj[start])
	    {
	        if(!vis[it])
	        {
	            dfs(it,st,vis,adj);
	        }
	    }
	    st.push(start);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] = {0};
	    vector<int> v;
	    stack<int> st;
	    
	    for(int i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i, st,vis, adj);
	        }
	    }
	    while(!st.empty())
	    {
	        v.push_back(st.top());
	        st.pop();
	    }
	    return v;
	}
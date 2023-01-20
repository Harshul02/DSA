bool isCyclic(int V, vector<int> adj[]) {
        //Using Topological Sort  
  int indegree[V] = {0};
	   
	   for(int i=0; i<V; i++)
	   {
	       for(auto it: adj[i])
	       {
	           indegree[it]++;
	       }
	   }
	   queue<int> q;
	   vector<int> v;
	   for(int i=0; i<V; i++)
	   {
	       if(!indegree[i])
	       {
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty())
	   {
	       int node = q.front();
	       q.pop();
	       v.push_back(node);
	       
	       for(auto it: adj[node])
	       {
	           indegree[it]--;
	           if(indegree[it] == 0)
	           {
	               q.push(it);
	           }
	       }
	   }
	   return !(v.size() == V);
    }
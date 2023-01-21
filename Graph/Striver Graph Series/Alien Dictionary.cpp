vector<int> topo(int V, vector<int> adj[])
    {
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
	   return v;
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0; i<N-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.length(), s2.length());
            
            for(int ptr=0; ptr<len; ptr++)
            {
                if(s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> top = topo(K, adj);
        string ans = "";
        for(auto it: top)
        {
            ans += char(it + 'a');
        }
        return ans;
    }
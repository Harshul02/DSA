int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0; i<flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int,pair<int,int>>> q;
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stop > k) continue;
            
            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                
                if(cost + edW < dist[adjNode] and stop<=k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stop+1, {adjNode, cost + edW}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
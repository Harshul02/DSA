int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e9);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                
                if(dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
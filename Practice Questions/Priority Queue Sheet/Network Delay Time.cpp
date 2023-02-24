int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int x = times.size();
        vector<pair<int,int>> adj[n+1];
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n+1, 1e9);
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int adjWeight = it.second;

                if(dist + adjWeight < dis[adjNode])
                {
                    dis[adjNode] = dist + adjWeight;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        int mini = INT_MIN;
        for(int i=1; i <= n; i++)
        {
            if(dis[i] == 1e9)
                return -1;
            mini = max(mini, dis[i]);
        }
        return mini;

    }
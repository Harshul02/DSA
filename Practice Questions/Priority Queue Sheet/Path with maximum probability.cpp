double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double maxi = 0.0;
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        queue<pair<int, double>> pq;
        pq.push({start, 1.0});

        while(!pq.empty())
        {
            int node = pq.front().first;
            double dis = pq.front().second;
            pq.pop();
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                double adjWeight = it.second;

                if(adjNode == end)
                {
                    double x = dis * adjWeight;
                    maxi = max(maxi, x);
                }

                if(dis * adjWeight > dist[adjNode])
                {
                    dist[adjNode] = dis*adjWeight;
                    pq.push({adjNode, dist[adjNode]});
                }
            }
        }
        return maxi;
}
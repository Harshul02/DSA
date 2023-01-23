vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {   
        //Using Set   
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it: adj[node])
            {
                int adjW = it[1];
                int adjNode = it[0];
                
                if(dis + adjW < dist[adjNode])
                {
                    if(dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                        dist[adjNode] = dis + adjW;
                        st.insert({dist[adjNode], adjNode});
                    
                }
            }
        }
        return dist;
    }
int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        //TC = O(100000 * arr.size());
        while(!q.empty())
        {
            int dis = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for(auto it: arr)
            {
                int num = (node * it) % 100000;
                if(dis + 1 < dist[num])
                {
                    dist[num] = dis + 1;
                    if(num == end) return dis + 1;
                    q.push({dis+1, num});
                }
            }
        }
        return -1;
    }
int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }

//--------------------------------------------------------------------------------------------------
// Optimized Approach

        int n = matrix.size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        for(int i=0; i<n; i++)
        {
            pq.push({matrix[i][0], {i,0}});
        }
        int ans = 0;
        while(!pq.empty() and k--)
        {
            int x = pq.top().second.first, y = pq.top().second.second;
            ans = pq.top().first;
            pq.pop();
            if(y != n-1)
                pq.push({matrix[x][y+1], {x, y+1}});
        }
        return ans;
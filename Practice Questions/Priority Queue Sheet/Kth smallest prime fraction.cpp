 vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int,int>>> pq;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            pq.push({-1.0*arr[i]/arr.back(), {i,n-1}});
        }
        
        while(--k>0)
        {
            auto tp = pq.top();
            pq.pop();
            int x = tp.second.first;
            int y = tp.second.second;
            y--;
            pq.push({-1.0*arr[x]/arr[y], {x,y}});
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
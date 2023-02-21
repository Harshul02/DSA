priority_queue<int, vector<int>, greater<int>> pq;
    int ind;
    KthLargest(int k, vector<int>& nums) {
        for(auto it: nums)
        {
            pq.push(it);
            if(pq.size() > k)
                pq.pop();
        }
        ind = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > ind) pq.pop();
        return pq.top();
    }
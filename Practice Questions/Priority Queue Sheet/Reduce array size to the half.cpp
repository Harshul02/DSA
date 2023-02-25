int minSetSize(vector<int>& arr) {
        int cnt = 0;
        unordered_map<int,int> mp;
        for(auto it : arr)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        int n = arr.size();
        int x=n;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        while(!pq.empty())
        {
            x = x-pq.top().first;
            pq.pop();
            if(x > n/2){
                cnt++;
            }
        }
        return cnt+1;
    }
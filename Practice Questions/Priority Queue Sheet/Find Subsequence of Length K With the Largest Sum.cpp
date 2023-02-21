vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i],i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<pair<int,int>> v;
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        sort(v.begin(), v.end(), [&](auto &a, auto &b){
            return a.second<b.second;
        });
        vector<int> ans;
        for(auto it : v)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
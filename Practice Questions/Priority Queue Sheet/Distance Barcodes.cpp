vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> mp;
        for(auto it : barcodes)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        auto block = pq.top();
        pq.pop();
        ans.push_back(block.second);
        block.first--;
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
            temp.first--;
            if(block.first>0)
                pq.push(block);
            block = temp;
        }
        return ans;
    }
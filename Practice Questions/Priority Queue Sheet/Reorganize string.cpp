string reorganizeString(string s) {
        map<char, int> mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        string ans = "";
        
        auto block = pq.top();
            pq.pop();
            ans = ans + block.second;
            block.first--;
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            ans += temp.second;
            temp.first--;
            if(block.first > 0)
                pq.push(block);
            block = temp;
        }
        if(block.first > 0)
            return "";
        return ans;
    }
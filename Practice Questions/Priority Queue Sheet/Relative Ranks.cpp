vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        unordered_map<int,string> mp;

        priority_queue<int> pq(score.begin(), score.end());

        for(int i=1; i<=score.size(); i++) {
            string s;
            if(i == 1) s = "Gold Medal";
            else if(i == 2) s = "Silver Medal";
            else if(i == 3) s = "Bronze Medal";
            else s = to_string(i);
            mp[pq.top()] = s;
            pq.pop();
        }
        for(auto x: score) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
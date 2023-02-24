int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int count = 0;
        for(auto ch : tasks)
        {
            mp[ch]++;
            count = max(count,mp[ch]);
        }
        int ans = (count-1)*(n+1);
        for(auto it : mp)
        {
            if(it.second == count) ans++;
        }
        return max((int)tasks.size(), ans);
    }
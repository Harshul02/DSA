int minSteps(string s, string t) {
        map<char,int> mp;
        int ans = 0;
        for(auto it : s)
        {
            mp[it]++;
        }
        for(auto it : t)
        {
            mp[it]--;
        }
        for(auto it : mp)
        {
            ans += abs(it.second);
        }
        return ans;
    }
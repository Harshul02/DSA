int minSteps(string s, string t) {
        map<char,int> mp;
        int cnt = 0;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it : mp)
        {
            cnt += abs(it.second);
        }
        return cnt/2;
    }
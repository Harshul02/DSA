vector<int> partitionLabels(string s) {
        vector<int> ans;

        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]] = i;
        }

        int prev = -1;
        int maxi = 0;
        for(int i=0; i<s.size(); i++)
        {
            maxi = max(maxi, mp[s[i]]);
            if(maxi == i)
            {
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return ans;
    }
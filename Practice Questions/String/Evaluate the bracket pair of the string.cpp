string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        string ans = "";
        for(auto it : knowledge)
        {
            mp[it[0]] = it[1];
        }
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')    
            {
                string sub ="";
                while(++i<s.length() and s[i] != ')')
                    sub += s[i];
                if(mp.count(sub))
                {
                    ans += mp[sub];
                }
                else ans += "?";
            }
            else ans += s[i];
        }
        return ans;
    }
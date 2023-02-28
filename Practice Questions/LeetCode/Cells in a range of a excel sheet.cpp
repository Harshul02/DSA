vector<string> cellsInRange(string s) {
        vector<string> v;

        for(char i = s[0]; i<=s[3]; i++)
        {
            for(char j = s[1]; j<=s[4]; j++)
            {
                v.push_back({i,j});
            }
        }
        return v;
    }
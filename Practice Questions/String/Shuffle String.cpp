string restoreString(string s, vector<int>& indices) {
        string t = s;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            t[indices[i]] = s[i];
        }
        return t;
    }
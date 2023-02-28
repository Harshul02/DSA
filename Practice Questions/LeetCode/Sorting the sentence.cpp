string sortSentence(string s) {
        vector<pair<int,string>> v;
        istringstream ss(s);
        string w;
        while(ss>>w)
        {
            int n = w.size();
            int i = w[n-1];
            w.pop_back();
            v.push_back({i,w});
        }

        sort(v.begin(), v.end());
        string a="";

        for(auto it : v)
        {
            a += it.second + " ";
        }
        a.pop_back();
        return a;
    }
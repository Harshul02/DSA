bool carPooling(vector<vector<int>>& t, int c) {
        // map<int,int> mp;
        // for(auto it : t)
        // {
        //     mp[it[1]] += it[0];
        //     mp[it[2]] -= it[0];
        // }
        // int sum = 0;
        // for(auto it : mp)
        // {
        //     sum += it.second;
        //     if(sum>c)
        //         return false;
        // }
        // return true;

        vector<int> v(1001, 0);
        for(auto it : t)
        {
            v[it[1]] += it[0];
            v[it[2]] -= it[0];
        }
        int sum = c;
        for(int i=0; i<1001 and sum>=0; i++)
        {
            sum -= v[i];
        }
        return sum>=0;
    }
int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), [&](auto a, auto b){
            return a[1] > b[1];
        });
        int sum = 0;
        for(auto it : b)
        {
            if(it[0] <= t)
            {
                sum += it[0]*it[1];
                t -= it[0];
            }
            else
            {
                sum += it[1]*t;
                t=0;
            }
        }
        return sum;
    }
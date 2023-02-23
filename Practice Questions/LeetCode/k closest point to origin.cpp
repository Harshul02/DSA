vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, pair<int,int>>> v;
        for(auto it : points)
        {
            v.push_back({it[0]*it[0] + it[1]*it[1], {it[0], it[1]}});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back({v[i].second.first, v[i].second.second});
        }
        return ans;
    }
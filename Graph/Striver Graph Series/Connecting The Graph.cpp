int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int cntExtra = 0;
        for(auto it: edge)
        {
            int u = it[0];
            int v = it[1];
            
            if(ds.findParent(u) == ds.findParent(v))
                cntExtra++;
            else{
                ds.unionBySize(u,v);
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.findParent(i) == i)
                cnt++;
        }
        int ans = cnt - 1;
        
        if(cntExtra >= ans)
            return ans;
        return -1;
    }
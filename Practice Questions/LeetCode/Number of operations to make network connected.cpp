class DisjointSet{
    //Union By Size
    vector<int> size,parent;

public:

DisjointSet(int n)
{
    size.resize(n+1);
    parent.resize(n+1);
    for(int i=0; i<=n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int findParent(int node)
{
    if(node == parent[node])
        return node;
    return findParent(parent[node]);
}

void unionBySize(int u, int v)
{
    int ulp_u = findParent(u) ;
    int ulp_v = findParent(v) ;

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}
};

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int cntExtra=0;
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) == ds.findParent(v))
                cntExtra++;
            else
                ds.unionBySize(u,v);
        }

        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(ds.findParent(i) == i)
                cnt++;
        }

        int ans = cnt-1;
        if(cntExtra >= ans)
            return ans;
        return -1;
    }
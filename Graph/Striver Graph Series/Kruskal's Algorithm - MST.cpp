class DisjointSet{
    vector<int> rank, parent;
    public:
    
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
        }
    }
    
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        return findParent(parent[node]);
    }
    
    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        //Using Kruskal's Algo - Disjoint Set
        // O(M)
        vector<pair<int,pair<int,int>>> edges;
        //O(M+E)
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                int adjNode = it[0];
                int edW = it[1];
                int node = i;
                 edges.push_back({edW, {node, adjNode}});
            }
        }
        //O(MlogM)
        sort(edges.begin(), edges.end());
        int maxWt = 0;
        DisjointSet ds(V);
        //O(M x 4 x alpha x 2)
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)){
                maxWt += wt;
                ds.unionByRank(u,v);
            }
        }
        return maxWt;
    }
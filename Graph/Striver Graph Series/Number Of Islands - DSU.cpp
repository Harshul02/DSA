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

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        vector<int> ans;
        
        for(auto it: operators)
        {
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++)
            {
                int adjR = row + dr[i];
                int adjC = col + dc[i];
                
                if(adjR>=0 and adjC>=0 and adjR<n and adjC<m)
                {
                    if(vis[adjR][adjC] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjR * m + adjC;
                        if(ds.findParent(nodeNo) != ds.findParent(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
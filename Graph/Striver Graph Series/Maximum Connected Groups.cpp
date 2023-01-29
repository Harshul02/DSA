class DisjointSet{
    //Union By Size

public:
    vector<int> size,parent;

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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        DisjointSet ds(n*n);
        //step - 1
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<n; col++)
            {
                if(grid[row][col] == 0)
                    continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                
                for(int i=0; i<4; i++)
                {
                    int newR = row + dr[i];
                    int newC = col + dc[i];
                    
                    if(newR>=0 and newR<n and newC>=0 and newC<n and grid[newR][newC] == 1)
                    {
                        int nodeNo = row *n + col;
                        int adjNodeNo = newR * n + newC;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        //step - 2
        int mx = 0;
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<n; col++)
            {
                if(grid[row][col] == 1)
                    continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                
                set<int> components;
                for(int i=0; i<4; i++)
                {
                    int newR = row + dr[i];
                    int newC = col + dc[i];
                    
                    if(newR>=0 and newR<n and newC>=0 and newC<n and grid[newR][newC] == 1)
                    {
                        components.insert(ds.findParent(newR*n + newC));
                    }
                }
                
                int sizeT = 0;
                for(auto it: components)
                {
                    sizeT += ds.size[it];
                }
                mx = max(mx,sizeT+1);
            }
        }
        
        //If all cells are 1
        for(int cell = 0; cell<n*n; cell++)
        {
            mx = max(mx, ds.size[ds.findParent(cell)]);
        }
        return mx;
    }
};
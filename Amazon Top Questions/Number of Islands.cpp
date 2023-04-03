class Solution {
public:

    void bfs(vector<vector<int>> &vis, vector<vector<char>> grid, int i, int j)
    {
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
        {
            int drow = row+ dr[i];
            int dcol = col+ dc[i];
            if(drow>=0 && drow<grid.size() && dcol>=0 && dcol<grid[0].size() && vis[drow][dcol] != 1 && grid[drow][dcol] == '1')
            {
                vis[drow][dcol] = 1;
                q.push({drow,dcol});
            }
        }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(vis, grid, i, j);
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int time = 0;
        queue<pair<int, pair<int,int>>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,{j,0}});
                }
            }
        }
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second.first;
            int ntime = q.front().second.second;
            q.pop();
            time = max(time, ntime);
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i= 0;i <4; i++)
            {
                int drow = row + dr[i];
                int dcol = col + dc[i];

                if(drow>=0 and drow<n and dcol>=0 and dcol<m and grid[drow][dcol]==1 and vis[drow][dcol] != 2){
                    vis[drow][dcol] = 2;
                    q.push({drow, {dcol, ntime + 1}});
                }
            }
        }
        for(int i = 0;i <n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 1 and vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};
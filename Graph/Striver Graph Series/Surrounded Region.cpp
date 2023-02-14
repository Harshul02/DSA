void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
        for(int i=0; i<4; i++)
        {
            int delr = row + dr[i];
            int delc = col + dc[i];
            if(delr>=0 and delr<n and delc>=0 and delc<m and vis[delr][delc] == 0 and board[delr][delc] == 'O')
            {
                dfs(delr,delc,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0; i<n; i++)
        {
            if(!vis[i][0] and board[i][0] == 'O')
            {
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] and board[i][m-1] == 'O')
            {
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(!vis[0][i] and board[0][i] == 'O')
            {
                dfs(0,i,vis,board);
            }
            if(board[n-1][i] == 'O' and !vis[n-1][i])
            {
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] == 0 and board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
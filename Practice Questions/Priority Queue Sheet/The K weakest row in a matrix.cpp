vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0; i<mat.size(); i++)
        {
            int cnt = 0;
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 1)
                    cnt++;
            }
            pq.push({cnt, i});
        }
        int ind=-1, count = -1;
        for(int i=0; i<k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
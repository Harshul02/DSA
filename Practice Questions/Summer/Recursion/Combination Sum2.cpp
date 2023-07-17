void fun(int i, int n, vector<vector<int>> &ans, vector<int> cand, int sum, vector<int> v)
    {
            if(sum == 0)
            {
                ans.push_back(v);
            return;
            }

        for(int ind = i; ind<n; ind++)
        {
            if(ind > i and cand[ind] == cand[ind-1]) continue;
            if(cand[ind] > sum) break;
    
            v.push_back(cand[ind]);
            fun(ind+1,n, ans, cand, sum - cand[ind], v);
            v.pop_back();
        }    
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n = cand.size();
        fun(0, n, ans, cand, target, v);
        return ans;
    }
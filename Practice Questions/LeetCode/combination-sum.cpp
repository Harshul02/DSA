void fun(int i, int tar, vector<int> cand, vector<int> &v, vector<vector<int>> &ans)
    {
        if(tar < 0)
            return;
        if(i == cand.size()){
        if(tar == 0)
        {
            ans.push_back(v);
            return;
        }
        return;
        }
        v.push_back(cand[i]);
        fun(i, tar-cand[i], cand, v, ans);
        v.pop_back();
        fun(i+1, tar, cand, v, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<vector<int>> ans;
        // int n = cand.size();
        // int sum = 0;
        vector<int> v;
        fun(0, t, cand, v, ans);
        return ans;
    }
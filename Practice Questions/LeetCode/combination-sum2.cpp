void fun(int ind, int tar, vector<vector<int>>& ans, vector<int> &v, vector<int> cand)
    {
        if(tar == 0)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i = ind; i<cand.size(); i++){
            if(i>ind and cand[i] == cand[i-1]) continue;
            if(cand[i] > tar)
                break;
        v.push_back(cand[i]);
        fun(i+1, tar-cand[i], ans, v, cand);
        v.pop_back();
        // fun(i+1, tar, ans, v, cand);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(cand.begin(), cand.end());
        fun(0,t,ans,v,cand);
        return ans;
    }
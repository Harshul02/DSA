void fun(int i, int n, vector<vector<int>> &ans, vector<int> a, int sum, vector<int> &v)
    {
        // if(sum<0)   return;
        if(i==n)
        {
            if(sum == 0)
            {
                // sort(v.begin(), v.end());
                ans.push_back(v);
            }
            return;
        }
        if(a[i] <= sum){
        v.push_back(a[i]);
        fun(i, n, ans, a, sum-a[i], v);
        v.pop_back();
        }
        fun(i+1, n, ans, a, sum, v);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        map<int, int> mp;
        for(auto it : A)
        {
            mp[it]++;
        }
        vector<int> v, a;
        for(auto it : mp)
        {
            a.push_back(it.first);
        }
        int n = a.size();

        fun(0, n, ans, a, B, v);
        return ans;
    }
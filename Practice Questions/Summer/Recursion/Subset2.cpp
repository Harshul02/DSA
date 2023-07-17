void fun(int i, int n, vector<int> v, set<vector<int>> &st, vector<int> nums)
    {
        if(i == n)
        {
            st.insert(v);
            return;
        }

        v.push_back(nums[i]);
        fun(i+1, n, v, st, nums);
        v.pop_back();
        fun(i+1, n, v, st, nums);
    }



    void fun1(int ind, int n, vector<int> v, vector<vector<int>> &ans, vector<int> nums)
    {
            ans.push_back(v);
        for(int i = ind; i<nums.size(); i++){
            if(i>ind and nums[i] == nums[i-1]) continue;

        v.push_back(nums[i]);
        fun1(i+1,n, v, ans, nums);
        v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // fun(0, n, v, st, nums);
        fun1(0, n, v, ans, nums);

        // for(auto it : st)
        // {
        //     ans.push_back(it);
        // }
        return ans;
    }
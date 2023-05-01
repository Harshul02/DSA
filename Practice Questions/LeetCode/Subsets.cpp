void fun(int i, vector<int>nums, vector<vector<int>>& ans, vector<int> v)
    {
        if(i == nums.size())
            return;
        
        v.push_back(nums[i]);
        fun(i+1, nums, ans, v);
        ans.push_back(v);
        v.pop_back();
        fun(i+1, nums, ans, v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> v;
        fun(0, nums, ans, v);
        // sort(ans.begin(), ans.end());
        return ans;
    }
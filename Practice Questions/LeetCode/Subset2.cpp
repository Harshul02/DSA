void fun(int ind, vector<int> nums, vector<int>& v, vector<vector<int>>& ans)
    {
        ans.push_back(v);

        for(int i = ind; i<nums.size(); i++){
            if(i>ind and nums[i] == nums[i-1]) continue;

        v.push_back(nums[i]);
        fun(i+1, nums, v, ans);
        v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        fun(0, nums, v, ans);
        return ans;
    }
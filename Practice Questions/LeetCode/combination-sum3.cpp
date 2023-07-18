void fun(int i, int sum, vector<int> v, vector<vector<int>> &ans, vector<int> nums, int k)
    {
        if(sum < 0)
            return;
        
        if(i > 8)
        {
            if(sum == 0 and v.size() == k)
            {
                ans.push_back(v);
            }
            return;
        }

        v.push_back(nums[i]);
        fun(i+1, sum - nums[i], v, ans, nums, k);
        v.pop_back();
        fun(i+1, sum, v, ans, nums, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i<=9; i++)
        {
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> v;
        fun(0, n, v, ans, nums, k);
        return ans;
    }
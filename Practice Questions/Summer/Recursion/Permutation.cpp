void fun(int n, map<int,int> &mp, vector<vector<int>> &ans, vector<int> v, vector<int> nums)
    {
        if(v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }

        for(int ind = 0; ind<n; ind++)
        {
            if(!mp[ind])
            {
                v.push_back(nums[ind]);
                mp[ind] = 1;
                fun(n, mp, ans, v, nums);
                mp[ind] = 0;
                v.pop_back();
            }
        }
    }

    void fun1(int ind, int n, vector<vector<int>> &ans, vector<int> nums)
    {
        if(ind == n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i<n; i++)
        {
                swap(nums[ind],nums[i]);
                fun1(ind+1, n, ans, nums);
                swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> v;
        // map<int,int> mp;
        int n = nums.size();
        // fun(n, mp, ans, v, nums);
        fun1(0, n, ans, nums);

        return ans;
    }
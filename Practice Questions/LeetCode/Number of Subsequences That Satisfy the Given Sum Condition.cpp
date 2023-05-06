int mod = 1e9 + 7;
    void fun(int i, vector<int> nums, vector<int> &v, int target, int &count)
    {
        if(i == nums.size()){
            if(v.size() > 0)
            {
                if(v[0] + v[v.size() -1] <= target)
                    (count++)%mod;
            }
            return;
        }

        v.push_back(nums[i]);
        fun(i+1, nums, v, target, count);
        v.pop_back();
        fun(i+1, nums, v, target, count);
    }

    int numSubseq(vector<int>& nums, int target) {
        // vector<int> v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n+1, 1);
        for(int i= 1; i<=n; i++)
            dp[i] = (2*dp[i-1])%mod;

        int left = 0, right = n-1;
        int count=0;
        // fun(0,nums,v,target, count);

        while(left<=right)
        {
            if(nums[left] + nums[right] <= target)
            {
                count = (count + dp[right-left])%mod;
                left++;
            }
            else right--;
        }
        return count;
    }
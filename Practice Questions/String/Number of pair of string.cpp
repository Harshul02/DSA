int numOfPairs(vector<string>& nums, string target) {
        if(nums.size() == 1 and nums[0] == target)
            return 1;

        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j= 0; j<n; j++)
            {
                if(nums[i] + nums[j] == target and i!=j)
                    cnt++;
            }
        }
        return cnt;
    }
vector<int> searchRange(vector<int>& nums, int target) {
        int res1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int res2 = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() -1;
        if(res1 < nums.size() and nums[res1]==target)
            return {res1,res2};
        return {-1,-1};
    }

// TC = O(log n)
// SC = O(1)
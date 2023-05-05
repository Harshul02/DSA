int binary(vector<int> &nums, int l, int r,int target)
    {
        if(l>r)
            return -1;
        
        int mid= (l+r)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            return binary(nums,l,mid-1,target);
        else
            return binary(nums,mid+1,r,target);
        
    }
    
    // TC = O(log n)
    int search(vector<int>& nums, int target) {
        // return binary(nums,0, nums.size()-1,target);
        int ind = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(ind!= nums.size() and nums[ind] == target)
            return ind;
        return -1;
    }
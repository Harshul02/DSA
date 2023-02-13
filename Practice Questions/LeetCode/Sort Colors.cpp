void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int j=0;
        for(auto it: mp)
        {
            while(it.second>0)
            {
                nums[j]=it.first;
                it.second--;
                j++;
            }
        }
    }
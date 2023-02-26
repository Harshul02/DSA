bool isPossible(vector<int>& nums) {
        map<int,int> mp, mp1;

        for(auto it : nums){
            mp[it]++;
        }
        for(auto it : nums)
        {
            if(mp[it] == 0)
                continue;
            mp[it]--;

            if(mp1[it-1] > 0)
            {
                mp1[it-1]--;
                mp1[it]++;
            }
            else if(mp[it+1] and mp[it+2])
            {
                mp[it+1]--;
                mp[it+2]--;
                mp1[it+2]++;
            }
            else return false;
        }
        return true;
    }
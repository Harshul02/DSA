vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        int maxKey = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                mp[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);
            }
        }
        for(int i=0; i<=maxKey; i++)
        {
            reverse(mp[i].begin(), mp[i].end());
            for(auto it : mp[i])
                ans.push_back(it);
        }
        return ans;
    }

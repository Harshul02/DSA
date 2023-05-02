class Solution {
public:

    void fun(vector<int> nums, vector<int>& freq, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i<nums.size(); i++)
        {
            if(freq[i] != 1)
            {
                freq[i] = 1;
                ds.push_back(nums[i]);
                fun(nums, freq, ans, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        fun(nums, freq, ans, ds);
        return ans;
    }
};
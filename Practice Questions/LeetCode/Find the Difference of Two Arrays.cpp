class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> st1(nums1.begin(), nums1.end()), st2(begin(nums2), end(nums2));
        // for(auto it : st1)
        // {
        //     if(st2.find(it) == st2.end())
        //     {
        //         ans[0].push_back(it);
        //     }
        // }
        // for(auto it : st2)
        // {
        //     if(st1.find(it) == st1.end())
        //     {
        //         ans[1].push_back(it);
        //     }
        // }
        set_difference(begin(st1), end(st1), begin(st2), end(st2),back_inserter(ans[0]));
        set_difference(begin(st2), end(st2), begin(st1), end(st1),back_inserter(ans[1]));
        return ans;
    }
};
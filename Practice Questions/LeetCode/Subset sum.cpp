void fun(int i, vector<int> arr, int sum, int n, vector<int> &ans)
    {
        if(i == n)
            return;
            
        // v.push_back(arr[i]);
        sum += arr[i];
        fun(i+1, arr, sum, n, ans);
        ans.push_back(sum);
        sum -= arr[i];
        fun(i+1, arr, sum, n, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int sum = 0;
        ans.push_back(0);
        fun(0, arr, sum, N, ans);
        return ans;
    }
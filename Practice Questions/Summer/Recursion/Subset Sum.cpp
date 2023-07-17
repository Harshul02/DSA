void fun(int i, int n, int sum, vector<int> &v, vector<int> arr)
    {
        if(i == n)
        {
            v.push_back(sum);
            return;
        }
        
        fun(i+1, n, sum + arr[i], v, arr);
        fun(i+1, n, sum, v, arr);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> v;
        fun(0,N, 0, v, arr);
        return v;
    }
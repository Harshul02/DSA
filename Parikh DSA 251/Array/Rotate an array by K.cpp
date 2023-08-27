vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n = arr.size();
    vector<int> ans(n);

    int x = 0;
    for(int i = k; i<n; i++)
    {
        ans[x++] = arr[i];
    }
    for(int i = 0; i<k; i++)
    {
        ans[x++] = arr[i];
    }
    return ans;
}

long long int fib(vector<long long int> &nums)
{
    long long int prev2 = 0;
    long long int prev = nums[0];

    for(int i=1; i<nums.size(); i++)
    {
        long long int take = nums[i];
        if(i>1)
            take += prev2;
        long long int notTake = 0 + prev;

        long long int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;

}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<long long int> temp, temp1;
    int n = valueInHouse.size();
    if(n==1)
        return valueInHouse[0];

    for(int i=0; i<n; i++)
    {
        if(i!=0) temp.push_back(valueInHouse[i]);
        if(i!=n-1) temp1.push_back(valueInHouse[i]);
    }
    return max(fib(temp), fib(temp1));
}

// TC = O(N)
// SC = O(1)
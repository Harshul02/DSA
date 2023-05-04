// Similar to tiling problem


// SC = O(N)
long long check(long long n, vector<int> &dp)
    {
        if(n<=1)
            return 1;
        if(dp[n]!= -1)
            return dp[n];
        return dp[n] = numberOfWays(n-1) + numberOfWays(n-2);
    }
    

    // TC = O(n)
    // SC = O(1)
    long long numberOfWays(long long n) {
        //code here
        int mod = 1e9 + 7;
        long long a = 1, b = 1, c;
        for(int i = 2; i<=n; i++)
        {
            c = (a+b)%mod;
            a=b, b=c;
        }
        return b;
    }
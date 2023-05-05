int mod = 1000000007;
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n==0)    return 1;
        if(n==1)    return 1;
        
        long int a = 1, b= 1, c;
        
        for(int i = 2; i<=n; i++)
        {
            c = (b + (i-1)*a)%mod;
            a=b, b=c;
        }
        return b;
    }


// TC = O(n)
// SC = O(1)
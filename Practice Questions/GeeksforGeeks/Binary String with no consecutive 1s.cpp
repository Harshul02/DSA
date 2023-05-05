// Recursion function =>    f(n) = f(n-1) + f(n-2)

// TC = O(n)
// SC = O(1)
int mod = 1e9 + 7;
	ll countStrings(int n) {
	    // code here
	    if(n==0) return 1;
	    if(n==1) return 2;
	    ll a= 1, b = 2, c;
	    
	    for(int i = 2; i<=n; i++)
	    {
	        c = (a+b)%mod;
	        a=b, b=c;
	    }
	    return b;
	}
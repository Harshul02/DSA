/*#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    if(n<=1)
        return n;
        
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<fibo(n, dp);
    return 0;
}
*/
// TC = O(N)
// SC = O(N)(Auxiliary Stack) + O(N)(Array)

//-----------------------------------------------------------------------------------------------------------------

/*#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<fibo(n, dp);
    return 0;
}

TC = O(N) 
SC = O(N) (Array)
*/
//-----------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int prev2 = 0;
    int prev = 1;
    
    for(int i=2; i<=n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev;
    return 0;
}

// TC = O(N)
// SC = O(1)
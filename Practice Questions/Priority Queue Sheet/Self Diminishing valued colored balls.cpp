int maxProfit(vector<int>& v, int ord) {
        sort(v.begin(), v.end());
        int n = v.size();
        long long ans=0;
        int mod = 1e9 + 7;
        for(int i=n-1; i>=0; i--)
        {
            long long diff = v[i] - (i>0?v[i-1]:0);
            long long x = min((long long)ord,(n-i)*diff);
            long long r = v[i];
            long long l = r - x/(n-i);
            ans += (r*(r+1)/2 - l*(l+1)/2)*(n-i);
            ans += l*(x%(n-i));
            ans = ans%mod;
            ord -= x;
        }
        return ans;
    }
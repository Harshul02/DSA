long long minimalKSum(vector<int>& nums, int k) {
        set<int> st;
        long long sum = (long)k*(k+1)/2;
        int cnt = 0;
        for(auto it : nums)
        {
            if(st.find(it) == st.end() and it<=k and it>=1)
            {
                sum -= it;
                cnt++;
            }
            st.insert(it);
        }

        int i = k+1;
        while(cnt>0)
        {
            if(st.find(i) == st.end()){
            sum += i;
            cnt--;
            }
            i++;
        }
        return sum;
    }
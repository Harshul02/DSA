int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for(auto it : bank)
        {
            int curr = count(it.begin(), it.end(), '1');
            if(curr)
            {
                res += prev * curr;
                prev = curr;
            }
        }
        return res;
    }
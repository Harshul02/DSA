void check(vector<string> &ans, string &s, int pos)
    {
        if(pos == s.length())
        {
            ans.push_back(s);
            return;
        }
        check(ans,s,pos+1);
        if(isalpha(s[pos]))
        {
            s[pos] ^= (1<<5);
            check(ans,s,pos+1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        if(s.length() == 0)
            return {s};

        check(ans,s,0);
        return ans;
    }
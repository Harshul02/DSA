string reverseParentheses(string s) {
        vector<int> v;
        string str = "";

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                v.push_back(str.length());
            else if(s[i] == ')')
            {
                int j = v.back();
                v.pop_back();
                reverse(str.begin() +j, str.end());
            }
            else str += s[i];
        }
        return str;
    }
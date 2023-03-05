int minAddToMakeValid(string s) {
        int op = 0, cl = 0;
        for(auto it : s)
        {
            if(it == '(')
                cl++;
            else if(cl > 0)
                cl--;
            else op++;
        }
        return op+cl;
    }
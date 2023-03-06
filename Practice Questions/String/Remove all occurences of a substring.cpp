string removeOccurrences(string s, string part) {
        int n = part.length();
        while(1)
        {
            int flag =true;
            for(int i=0; i<=s.length() - n; i++)
            {
                string sub = "";
                if(s.length() >= n)
                    sub = s.substr(i, n);
                else break;
                if(sub == part)
                {
                    s.erase(i,n);
                    flag=false;
                    i=-1;
                }
            }
            if(flag)
            {
                break;
            }
        }
        return s;
    }
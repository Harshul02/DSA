int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i<=n-m; i++)
        {
            string sub = haystack.substr(i, m);
            if(needle == sub)
                return i;
        }
        return -1;
    }
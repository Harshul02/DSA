int minSwaps(string s) {
        int bal = 0;
        int j = s.length() -1, cnt =0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '[')
                bal++;
            else bal--;

            if(bal<0)
            {
                while(j>i and s[j] != '[')
                    j--;
                swap(s[i], s[j]);
                cnt++;
                bal=1;
            }
        }
        return cnt;
    }
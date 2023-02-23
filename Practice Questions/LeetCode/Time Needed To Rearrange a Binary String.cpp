int secondsToRemoveOccurrences(string s) {
        int cnt=0;
        while(1)
        {
            bool flag=false;
            for(int i=0; i<s.length()-1; i++)
            {
                if(s[i] == '0' and s[i+1] == '1')
                {
                    swap(s[i], s[i+1]);
                    i++;
                    flag=true;
                }
            }
            if(flag==true){
                cnt++;
            }
            if(!flag){
                break;
            }
        }
        return cnt;
    }
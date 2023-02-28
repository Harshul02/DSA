int mostWordsFound(vector<string>& s) {
        // int mx=INT_MIN;//max spaces
        // for(int i=0;i<sentences.size();i++){
        //     int cnt=0;
        //     for(int j=0;j<sentences[i].size();j++){
        //         cnt+=sentences[i][j]==' '?1:0;//if it is a space increase count
        //     }
        //     mx=max(mx,cnt);
        // }
        // return mx+1;//total

        int maxCount = 0;
        for(auto it : s)
        {
            maxCount = max(maxCount, (int)count(it.begin(), it.end(), ' '));
        }
        
        return maxCount+1;
    }
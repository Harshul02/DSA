int numJewelsInStones(string J, string S) {
    //     int res = 0;
    //     unordered_set<char> setJ(J.begin(), J.end());
    //     for (char s : S)
    //         if (setJ.count(s)) res++;
    //     return res;
    // 
    int res = 0;
    for(int i=0; i<J.length(); i++)
    {
        res += count(S.begin(), S.end(), J[i]);
    }
    return res;
    }
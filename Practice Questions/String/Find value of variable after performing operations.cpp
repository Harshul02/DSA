int finalValueAfterOperations(vector<string>& op) {
        // int x=0;
        // for(int i=0; i<op.size(); i++)
        // {
        //     if(op[i][0]== '+' || op[i][2]=='+')
        //         x++;
        //     else
        //         x--;
        // }
        // return x;

        int cnt=0;
        for(auto x : op)
        {
            istringstream ss(x);
            string w;
            while(ss>>w){
                if(w[1] == '+')
                    cnt++;
                else cnt--;
            }
        }
        return cnt;
    }
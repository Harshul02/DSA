int maximumScore(int a, int b, int c) {
        priority_queue<int> q;
        q.push(a);
        q.push(b);
        q.push(c);
        int z=0;
        while(q.size()>1)
        {
            int x=q.top();
            q.pop();
            x--;
            int y=q.top();
            q.pop();
            y--;
            if(x!=0)
                q.push(x);
            if(y!=0)
                q.push(y);
            z++;
        }
        return z;
    }
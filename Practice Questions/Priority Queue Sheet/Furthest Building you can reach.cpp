int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        // priority_queue<int,vector<int>,greater<int>> q;
        // int n = h.size();
        // for(int i = 1;i<n;i++){
        //     if(h[i] <= h[i - 1])
        //      continue;

        //     q.push(h[i] - h[i - 1]);

        //     if(q.size() > ladders){
        //         bricks -= q.top();
        //         q.pop();
        //         if(bricks < 0) return i - 1;
        //     }
        // }
        // return n - 1;

        priority_queue<int, vector<int>> pq;
        int n = h.size();
        int i;
        for(i=0; i<n-1; i++)
        {
            int diff = h[i+1]-h[i];
            if(diff >0)
            {
                bricks -= diff;
                pq.push(diff);
                if(bricks<0)
                {
                    if(ladders <= 0) return i;
                    ladders--;
                    bricks += pq.top();
                    pq.pop();
                }
            }
        }
        return i;
    }
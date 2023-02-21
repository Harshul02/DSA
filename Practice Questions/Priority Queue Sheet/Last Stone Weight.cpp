int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto it : stones)
        {
            pq.push(it);
        }
        while(pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(pq.empty())
            {
                return y-x;
            }
            if(x!=y)
            {
                pq.push(y-x);
            }
        }
        return pq.top();
    }
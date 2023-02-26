int eatenApples(vector<int>& apples, vector<int>& days) {
        int d = 1;
        int ans = 0;
        priority_queue<pair<int,int>> pq;
        int i=0;
        while(i<apples.size() || !pq.empty())
        {
            if(i<apples.size())
                pq.push({-(d+days[i]), apples[i]});
            i++;
            while(!pq.empty() and -pq.top().first<=d) pq.pop();
            if(pq.size())
            {
                auto a = pq.top();
                pq.pop();
                a.second--;
                ans++;
                if(a.second>0) pq.push(a);
            }
            d++;
        }
        return ans;
    }
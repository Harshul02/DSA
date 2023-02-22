int fillCups(vector<int>& amount) {
        int maxS = 0;
        int sum = 0;
        for(auto it : amount)
        {
            maxS = max(maxS, it);
            sum += it;
        }
        return max(maxS, (sum +1)/2);
    }
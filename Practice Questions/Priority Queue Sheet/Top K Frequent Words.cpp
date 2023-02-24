struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<string> v;
        for(int i=0; i<words.size(); i++)
        {
            m[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for(auto p : m)
            q.push({p.second, p.first});
        
        while(k--) {
            v.push_back(q.top().second);
            q.pop();
        }
        
        return v;
    }
};
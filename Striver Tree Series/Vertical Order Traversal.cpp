vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root)
            return ans;
            
        // Queue :- Node, Level, Vertical
        queue<pair<Node *,pair<int,int>>> q;
        // Map :- vertical, level, Nodes
        map<int, map<int, vector<int>>> mp;
        q.push({root, {0,0}});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *temp = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].push_back(temp->data);
            if(temp->left)
                q.push({temp->left, {x-1, y+1}});
            if(temp->right)
                q.push({temp->right, {x+1, y+1}});
        }
    
        for(auto it : mp)
        {
            for(auto qn : it.second)
            {
                ans.insert(ans.end(), qn.second.begin(), qn.second.end());
            }
        }
        return ans;
    }
vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root)
            return ans;
            
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root, 0});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *temp = p.first;
            int level = p.second;
            mp[level] = temp->data;
            if(temp->left)
                q.push({temp->left, level-1});
            if(temp->right)
                q.push({temp->right, level+1});
        }
        
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
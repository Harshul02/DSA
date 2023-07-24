void findParent(Node *root, unordered_map<Node*, Node*> &track)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(t->left)
            {
                track[t->left] = t;
                q.push(t->left);
            }
            if(t->right)
            {
                track[t->right] = t;
                q.push(t->right);
            }
        }
    }
  
    Node* findNode(Node *root, int target)
    {
        if(!root) return NULL;
        
        if(root->data == target)
            return root;
        
        Node *t = findNode(root->left, target);
        if(t)   return t;
        return findNode(root->right, target);
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*, Node*> track;
        findParent(root, track);
        
        Node *t = findNode(root, target);
        // cout<<t->data<<endl;
        queue<Node*> q;
        q.push(t);
        unordered_map<Node*, bool> vis;
        vis[t] = true;
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i<size; i++)
            {
                t = q.front();
                q.pop();
                
                if(t->left and !vis[t->left])
                {
                    q.push(t->left);
                    vis[t->left] = true;
                }
                if(t->right and !vis[t->right])
                {
                    q.push(t->right);
                    vis[t->right] = true;
                }
                if(track[t] and !vis[track[t]])
                {
                    q.push(track[t]);
                    vis[track[t]] = true;
                }
            }
            level++;
        }
        return level-1;
    }
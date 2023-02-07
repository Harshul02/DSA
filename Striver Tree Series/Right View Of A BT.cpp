void dfs(Node *root, vector<int> &ans, int level)
    {
        if(!root)
            return;
            
        if(ans.size() == level)
            ans.push_back(root->data);
        dfs(root->right, ans, level+1);
        dfs(root->left, ans, level +1);
    }
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(!root)
        return ans;
        
        dfs(root, ans, 0);
        return ans;
    }
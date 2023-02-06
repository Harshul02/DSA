bool isLeaf(Node *root)
    {
        if(!root->left and !root->right)
            return true;
            
        return false;
    }

    void addLeft(Node* root, vector<int> &ans)
    {
        Node *curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left)
                curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void inorder(Node *root, vector<int> &ans)
    {
        if(!root)
            return;
            
        inorder(root->left, ans);
        if(isLeaf(root))
            ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    void addRight(Node *root, vector<int> &ans)
    {
        stack<int> st;
        Node* curr = root->right;
        while(curr)
        {
            if(!isLeaf(curr)) st.push(curr->data);
            if(curr->right)
                curr = curr->right;
            else
                curr= curr->left;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root)
            return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeft(root, ans);
        inorder(root,ans);
        addRight(root, ans);
        return ans;
    }

    // TC = O(N)
    // SC = O(Height Of Tree)
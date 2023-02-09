void preorder(Node *root, int &ans)
    {
        if(!root)
            return;
            
        if(root->left && root->right)
        {
            if(root->left->data + root->right->data != root->data)
                ans=0;
        }
        if(root->left && !root->right)
        {
            if(root->left->data != root->data)
                ans=0;
        }
        if(!root->left && root->right)
        {
            if(root->right->data != root->data)
                ans=0;
        }
        if(root->left)
            preorder(root->left, ans);
        if(root->right)
            preorder(root->right, ans);
    }
    
    int isSumProperty(Node *root)
    {
     // Add your code here
     int ans = 1;
     if(!root->left && !root->right)
        return ans;
     preorder(root,ans);
     return ans;
    }
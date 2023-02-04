int check(Node *root)
    {
        if(!root)
            return 0;
        
        int lh = check(root->left);
        if(lh == -1) return -1;
        int rh = check(root->right);
        if(rh == -1) return -1;
        
        if(abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }

    //O(N) approach
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return check(root) != -1;
    }
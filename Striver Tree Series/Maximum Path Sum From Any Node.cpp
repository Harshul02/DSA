int height(Node*root, int &maxi)
    {
        if(!root)
        return 0;
        
        int lh = max(0,height(root->left, maxi));
        int rh = max(0,height(root->right, maxi));
        
        maxi = max(maxi, lh+rh+root->data);
        
        return root->data + max(lh,rh);
    }
    
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int maxi = root->data;
        height(root, maxi);
        return maxi;
    }

    // TC = O(N)
    // SC = O(N) if skew tree else O(Height Of Tree)
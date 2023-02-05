int maxDepth(Node *root) {
        // Your code here
        if(!root)
            return 0;
            
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh,rh);
    }
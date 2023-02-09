Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(!root || root->data == n1 || root->data == n2)
        return root;
    
        Node* lh = lca(root->left, n1, n2);
        Node* rh = lca(root->right, n1, n2);
        
        if(!lh)
            return rh;
        else if(!rh)
            return lh;
        else return root;
    }
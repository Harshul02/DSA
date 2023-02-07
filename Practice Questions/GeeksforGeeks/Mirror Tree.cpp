void inorder(Node *node)
    {
        if(!node)
            return;
        
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        inorder(node->left);
        inorder(node->right);
    }
    
    void mirror(Node* node) {
        // code here
        inorder(node);
    }
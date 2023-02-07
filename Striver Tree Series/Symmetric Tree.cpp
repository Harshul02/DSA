bool check(Node *root1, Node *root2)
    {
        if(!root1 || !root2)
            return root1 == root2;
            
        if(root1->data != root2->data)
            return false;
        
        return check(root1->left, root2->right) and check(root1->right, root2->left);
    }
    
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(!root)
	        return true;
	    return check(root->left, root->right);
    }
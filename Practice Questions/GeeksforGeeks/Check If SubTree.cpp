bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(T)
        {
            if(S)
            {
                return ((T->data == S->data && isSubTree(T->left, S->left) && isSubTree(T->right,S->right)) || isSubTree(T->left,S) || isSubTree(T->right,S));
            }
        }
        else if(!T and !S)
            return true;
        return false;
    }
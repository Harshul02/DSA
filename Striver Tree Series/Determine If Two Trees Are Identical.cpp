bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right) && r1->data == r2->data;
    }

    // TC = O(N)
    // SC = O(N) if Skew Tree else O(Height of Tree)
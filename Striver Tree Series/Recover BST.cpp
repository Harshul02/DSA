void fun(TreeNode *root)
    {
        if(!root)
            return;

        fun(root->left);
        if(prev and root->val < prev->val)
        {
            if(!first)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        fun(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        fun(root);
        if(first and last)  swap(first->val, last->val);
        else if(first and middle)   swap(first->val, middle->val);
    }
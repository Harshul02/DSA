int findLeft(TreeNode *root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }

    int findRight(TreeNode *root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        if(!root)   return 0;

        int lh = findLeft(root);
        int rh = findRight(root);

        if(lh == rh)
        {
            return pow(2, lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
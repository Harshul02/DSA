TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return Tree(inorder, postorder, 0, idx, idx);
    }

    TreeNode *Tree(vector<int> inorder, vector<int> postorder, int left, int right, int &idx)
    {
        if(left > right)    return NULL;

        int pivot = left;
        while(inorder[pivot] != postorder[idx]) pivot++;

        idx--;
        TreeNode *root = new TreeNode(inorder[pivot]);
        root->right = Tree(inorder, postorder, pivot+1, right, idx);
        root->left = Tree(inorder, postorder, left, pivot-1, idx);
        return root;
    }

// TC = O(N)
// SC = O(H)
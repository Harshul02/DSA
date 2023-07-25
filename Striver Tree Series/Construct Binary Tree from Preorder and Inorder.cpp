TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return Tree(preorder, inorder, idx, 0, inorder.size()-1);
    }


TreeNode* Tree(vector<int> preorder, vector<int> inorder, int &rootIdx, int left, int right)
{
    if(left > right)    return NULL;

    int pivot = left;
    while(inorder[pivot] != preorder[rootIdx])  pivot++;

    rootIdx++;

    TreeNode *root = new TreeNode(inorder[pivot]);
    root->left = Tree(preorder, inorder, rootIdx, left, pivot-1);
    root->right = Tree(preorder, inorder, rootIdx, pivot+1, right);

    return root;
}

// TC = O(N)
// SC = O(H)
int height(Node *root, int &ans)
  {
      if(!root)
        return 0;
        
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        
        ans = max(ans, lh+rh);
        return 1 + max(lh,rh);
  }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int ans = 0;
        height(root, ans);
        return ans+1;
    }

    // TC = O(N)
    //SC = O(N)     Worst case if it is a skew tree else height of tree
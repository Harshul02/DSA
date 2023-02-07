void preorder(Node *root, int level, vector<int> &v)
{
    if(!root)
        return;
    
    if(level == v.size())
        v.push_back(root->data);
    
    preorder(root->left, level + 1, v);
    preorder(root->right, level + 1, v);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   int level = 0;
   vector<int> v;
   preorder(root, level, v);
   return v;
}
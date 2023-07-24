void fun(Node *root, vector<int> &ans, int k, int level)
{
    if(!root)   return;
    
    if(level == k)
    {
        ans.push_back(root->data);
        return;
    }
    
    fun(root->left, ans, k, level+1);
    fun(root->right, ans, k, level+1);
}

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int> ans;
  fun(root, ans, k, 0);
  return ans;
}
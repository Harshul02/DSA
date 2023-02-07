void preorder(Node *node, vector<int> &ans)
{
    if(!node)
        return;
        
    if(!node->left and node->right)
        ans.push_back(node->right->data);
    if(node->left and !node->right)
        ans.push_back(node->left->data);
        
    preorder(node->left, ans);
    preorder(node->right, ans);
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int> ans;
    preorder(node, ans);
    if(ans.size() == 0)
        return {-1};
    sort(ans.begin(), ans.end());
    return ans;
}
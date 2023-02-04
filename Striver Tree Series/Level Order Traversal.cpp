vector<vector<int>> levelOrder(Node* node)
{
  //Your code here
  vector<vector<int>> ans;
  if(!node)
    return ans;
    
    queue<Node *> q;
    q.push(node);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> v;
        for(int i =0; i<size; i++)
        {
            Node *temp = q.front();
            q.pop();
            v.push_back(temp->data);
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        ans.push_back(v);
    }
    return ans;
}
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> v;
    if(!root)
        return v;
        
    queue<Node *> q;
    bool flag = false;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> vt;
        for(int i=0; i<size; i++)
        {
            Node *t = q.front();
            q.pop();
            vt.push_back(t->data);
            if(t->left)
            {
                q.push(t->left);
            }
            if(t->right)
            {
                q.push(t->right);
            }
        }
        if(!flag)
        {
            reverse(vt.begin(), vt.end());
        }
            for(int i=0; i<vt.size(); i++)
            {
                v.push_back(vt[i]);
            }
        
        
        flag = !flag;
    }
    return v;
}
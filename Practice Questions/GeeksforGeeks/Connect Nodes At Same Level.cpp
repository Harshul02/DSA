void connect(Node *root)
    {
       // Your Code Here
       if(!root)
        return;
        
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            Node *temp = NULL;
            for(int i=0; i<size; i++)
            {
                Node *curr = q.front();
                q.pop();
                curr->nextRight = temp;
                temp = curr;
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
        }
    }
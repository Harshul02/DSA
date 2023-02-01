Node* connect(Node* root) {
        if(!root)
            return NULL;

        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            Node *rightNode = NULL;
            for(int i=0; i<size; i++)
            {
                auto curr = q.front(); q.pop();            
                curr -> next = rightNode;                  
                rightNode = curr;  
                if(curr->right)
                {
                    q.push(curr->right);
                }
                if(curr->left){
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
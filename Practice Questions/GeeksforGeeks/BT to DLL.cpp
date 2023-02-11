Node *l = NULL;
        int x = 0;
        
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root)
            return root;
            
        Node *head = bToDLL(root->left);
        if(x==0)
        {
            head = root;
            x++;
            l=head;
        }
        else{
            Node *temp = new Node(root->data);
            l->right = temp;
            temp->left = l;
            l = temp;
        }
        bToDLL(root->right);
        return head;
    }
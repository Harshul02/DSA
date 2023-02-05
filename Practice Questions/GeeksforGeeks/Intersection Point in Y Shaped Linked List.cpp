int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        Node *x = head1, *y = head2;
        while(x!=y)
        {
            x=x->next;
            y=y->next;
            if(x==NULL) x=head2;
            if(y==NULL) y=head1;
        }
        return x->data;
    }
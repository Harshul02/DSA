vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        if(!node)
            return ans;
            
        stack<Node*> st1;
        stack<int> st2;
        st1.push(node);
        while(!st1.empty())
        {
            Node *temp = st1.top();
            st1.pop();
            st2.push(temp->data);
            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
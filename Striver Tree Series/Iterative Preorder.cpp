vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> ans;
        if(!root)
            return ans;
        
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ans;
    }
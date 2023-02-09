int getMaxWidth(Node* root) {

        // Your code here
         if(root == NULL)
            return 0;
        int res = 0;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            res = max(res, cnt);
            for(int i=0; i<cnt; ++i) {
                Node *n = q.front();
                q.pop();
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
        }
        return res;
    }
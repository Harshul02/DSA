// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";

        queue<TreeNode*> q;
        q.push(root);
        string str = "";
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if(!curr)   str.append("#,");
            else str.append(to_string(curr->val) + ',');
            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)    return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#") curr->left = NULL;
            else{
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }

            getline(s, str, ',');
            if(str == "#")  curr->right = NULL;
            else{
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
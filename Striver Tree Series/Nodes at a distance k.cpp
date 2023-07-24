void markParent(unordered_map<TreeNode*, TreeNode*> &track, TreeNode *root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if(curr->left)
            {
                track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> track;
        markParent(track, root);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(level == k) break;
            level++;

            for(int i = 0; i<size; i++)
            {
                auto t = q.front();
                q.pop();
                if(t->left and !vis[t->left])
                {
                    vis[t->left] = true;
                    q.push(t->left);
                }
                if(t->right and !vis[t->right])
                {
                    vis[t->right] = true;
                    q.push(t->right);
                }
                if(track[t] and !vis[track[t]])
                {
                    vis[track[t]] = true;
                    q.push(track[t]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
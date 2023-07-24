int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root)
            return ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
                int first, last;
            for(int i = 0; i<size; i++)
            {
                long int curr = q.front().second - mini;
                TreeNode *node = q.front().first;
                q.pop();
                if(i == 0) first = curr;
                if(i == size-1) last = curr;

                if(node->left)  
                    q.push({node->left, 2*curr+1});
                if(node->right)
                    q.push({node->right, 2*curr+2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() or !q2.empty())
        {
            vector<int> v1,v2;
            int size = q1.size();
            for(int i=0; i<size; i++)
            {
                Node *temp1 = q1.front();
                q1.pop();
                Node *temp2 = q2.front();
                q2.pop();
                v1.push_back(temp1->data);
                v2.push_back(temp2->data);
                if(temp1->left)
                    q1.push(temp1->left);
                if(temp1->right)
                    q1.push(temp1->right);
                if(temp2->left)
                    q2.push(temp2->left);
                if(temp2->right)
                    q2.push(temp2->right);
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            for(int i=0; i<v1.size(); i++)
            {
                if(v1[i] != v2[i])
                    return false;
            }
        }
        return true;
    }
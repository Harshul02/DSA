vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	if(!root)
    	    return ans;
    	    
    	queue<Node *> q;
    	q.push(root);
    	int level = 0;
    	while(!q.empty())
    	{
    	    vector<int>v;
    	    int size = q.size();
    	    for(int i=0; i<size; i++)
    	    {
    	        Node *temp = q.front();
    	        q.pop();
    	        v.push_back(temp->data);
    	        
    	        if(temp->left)
    	            q.push(temp->left);
    	        if(temp->right)
    	            q.push(temp->right);
    	    }
    	    if(level % 2 != 0)
    	    {
    	        reverse(v.begin(), v.end());
    	    }
    	    for(auto it : v)
    	       ans.push_back(it);
    	       level++;
    	}
    	return ans;
    }
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int n = products.size();
        
        string an = "" ;
        for(int i=0; i<searchWord.size(); i++)
        {
            an += searchWord[i];
            vector<string> v;
            for(int j=0; j<n; j++)
            {
                string sub = products[j].substr(0,i+1);
                if(sub == an and v.size() < 3)
                    v.push_back(products[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
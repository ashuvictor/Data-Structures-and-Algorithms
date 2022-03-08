    vector<int> topView(Node *root)
    {
       vector<int>ans;
       if(root==NULL)
       return ans;
       queue<pair<Node*,int>>q;
       map<int,int>m;
       q.push({root,0});
       while(!q.empty()){
           Node* t=q.front().first;
           int h=q.front().second;
           q.pop();
           if(!m[h])
           m[h]=t->data;
           if(t->left)
           q.push({t->left,h-1});
           if(t->right)
           q.push({t->right,h+1});
       }
       for(auto x:m)
       ans.push_back(x.second);
       return ans;
    }

};
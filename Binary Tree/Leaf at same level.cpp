void solve(Node* root,vector<int>& ans,int level)
    {
        if(root == NULL) return ;
        
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(level);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
        return ;
    }
    bool check(Node *root)
    {
        //Your code here
        if(root == NULL) return false;
        vector<int> ans;
        solve(root,ans,0);
        int val = ans[0];
        for(int i=1;i<ans.size();i++)
        {
            if(val != ans[i])
            {
                return false;
            }
        }
        return true;
    }

bool check(Node *root)
    {
       queue<Node*>q;
       q.push(root);
     
       while(!q.empty()){
           int sz=q.size();
           int cnt=0;
           for(int i=0;i<sz;i++){
               Node *cur=q.front();
               q.pop();
               if(cur->left==NULL&&cur->right==NULL)cnt++;
               if(cur->left)q.push(cur->left);
               if(cur->right)q.push(cur->right);
           }
           if(cnt&&cnt!=sz)return false;
       }
       return true;
    }
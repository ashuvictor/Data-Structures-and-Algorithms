


unordered_map<string,int>mapi;
   string solve(Node*root){
       if(root==NULL)return "&";
        if(root->left==NULL and root->right==NULL){
           return to_string(root->data);
       }
       string ans="";
       ans+=to_string(root->data);
      
       ans+=solve(root->left);
       ans+=solve(root->right);
       mapi[ans]++;
       return ans;
   }
   int dupSub(Node *root) {
        // code here
        if(root==NULL)return 0;
        solve(root);
        for(auto x:mapi){
            if(x.second>=2){
                return 1;
            }
        }
        return 0;
   }
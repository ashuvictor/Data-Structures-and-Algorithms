


vector<Node*>ans;
   unordered_map<string,int>m;
   string solve(Node*root){
       if(!root)
       return "$";
       string s=" ";
       s=s+to_string(root->data);
       s=s+solve(root->left);
       s=s+solve(root->right);

       m[s]++;
       if(m[s]==2){
       ans.push_back(root);
       }
       return s;

  }
   vector<Node*> printAllDups(Node* root){

       ans.clear();
       m.clear();
       solve(root);
       return ans;
      
   }
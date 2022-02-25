https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
vector<int> leftView(Node *root)
{
   vector<int>ans;
   if(root==NULL)
   return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       int sz=q.size();
       ans.push_back(q.front()->data);
       while(sz--){
           Node* t;
           t=q.front();
           q.pop();
           if(t->left)
           q.push(t->left);
           if(t->right)
           q.push(t->right);
       }
   }
   return ans;
}
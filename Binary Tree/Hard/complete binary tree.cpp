
class Solution{
public:    
int countNodes(Node* root){
    if(root==NULL)
    return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}
bool solve(Node* root,int i,int n){
    if(root==NULL)
    return true;
    if(i>=n)
    return false;
    bool l=solve(root->left,2*i+1,n);
    bool r=solve(root->right,2*i+2,n);
    return l && r;
}
    bool isCompleteBT(Node* root){
        //code here
        int n=countNodes(root);
        return solve(root,0,n);
    }
};
class Solution{
public:    
   bool isCompleteBT(Node* root){

       if(root == NULL)return true;
       queue<Node*> q;
       
       q.push(root);
       
       while(!q.empty()){
          Node* head=q.front();
          q.pop();
          if(head== NULL and q.size()>=1){
              if(q.front()==NULL)return true;
              else return false;
          }
          
          q.push(head->left);
          q.push(head->right);
       }
       return true;
   }
};
class Solution{
public:    
    bool isCompleteBT(Node* root){
        //code here
        if(!root)
        return true;
        queue<Node*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--){
                Node* t=q.front();
                q.pop();
                if(t->left)
                {q.push(t->left);
                    if(flag)
                    return false;
                }
                else
                {
                    flag=true;
                }
                if(t->right){
                    q.push(t->right);
                    if(flag)
                    return false;
                }
                 else
                {
                    flag=true;
                }
            }
        }
        return true;
    }
};
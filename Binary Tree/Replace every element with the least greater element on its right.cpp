

vector<int> findLeastGreater(vector<int>& arr, int n) {
       set <int> s;
       vector <int> v(n,0);
       
       for(int i = n-1 ; i>=0 ; i--)
       {
           auto it = s.upper_bound(arr[i]);
           if(it == s.end())
               v[i] = -1;
           else
               v[i] = *it;
           s.insert(arr[i]);
       }
       return v;
   }
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insert(Node *root,int d){
    if(root==NULL){
        Node *root=new Node(d);
        return root;
    }
    if(d<root->data)root->left=insert(root->left,d);
    if(d>root->data)root->right=insert(root->right,d);
    return root;
}

Node *inorderSuc(Node *root,int k){
    Node* temp=root;

    Node *suc=NULL;
while(temp!=NULL){
    if(temp->data<=k)temp=temp->right;
    else{
        suc=temp;
        temp=temp->left;
    }
}
return suc;
}

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
 vector<int>ans(n);
     Node *root=NULL;
 for(int i=n-1;i>=0;i--){
     root=insert(root,arr[i]);
     Node *temp=inorderSuc(root,arr[i]);
     if(temp==NULL)ans[i]=-1;
     else ans[i]=temp->data;
 }
 return ans;
    }
};
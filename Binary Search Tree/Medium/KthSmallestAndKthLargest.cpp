Kth smallest and largest
  int ans;
    // Return the Kth smallest element in the given BST 
    void solve(Node *root,int k,int &idx){
        if(!root)
        return;
        solve(root->left,k,idx);
        if(k==idx){
            ans=root->data;
            idx++;
            return;
        }
        else{
            idx++;
        }
        solve(root->right,k,idx);
    }
    int KthSmallestElement(Node *root, int K)
    {
      int idx=1;
     ans=-1;
        solve(root,K,idx);
        return ans;
    }
     int ans;
    void solve(Node* root,int k,int &idx){
        if(!root){
            return;
        }
        solve(root->right,k,idx);
        if(k==idx){
            ans=root->data;
            idx++;
            return;
        }
        else{
            idx++;
        }
        solve(root->left,k,idx);
    }
    int kthLargest(Node *root, int K)
    {
        int idx=1;
        ans=-1;
        solve(root,K,idx);
        return ans;
    }

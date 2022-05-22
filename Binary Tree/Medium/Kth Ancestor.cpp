Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.


Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the function kthAncestor(), 
the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.



bool isPossible(Node *root,int node, vector <Node*> &arr){
   if(root==NULL)
       return false;
   arr.push_back(root);
   if(root->data==node)
       return true;
   if(isPossible(root->left,node,arr) or isPossible(root->right,node,arr))
       return true;
   arr.pop_back();
   return false;
}
int kthAncestor(Node *root, int k, int node)
{
   // Code here
   vector <Node*> arr;
   if(isPossible(root,node,arr)){
       // return arr[arr.size()-1-k]->data;
       return k<arr.size() ? arr[arr.size()-1-k]->data : -1;
   }
   return -1;
}



Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}
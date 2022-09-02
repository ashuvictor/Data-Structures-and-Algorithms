https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

complete binary tree and node greater than the the chidren
class Solution {
  public:
  int countNodes(Node* root){
      if(root==NULL)
        return 0;
    
        int ans=1+countNodes(root->left)+countNodes(root->right);
        return ans;
  }
  
  bool isCBT(Node* root,int i,int n){
      if(root==NULL)
        return true;
    
        if(i>=n)
        return false;
        
        bool left=isCBT(root->left,2*i+1,n);
        bool right=isCBT(root->right,2*i+2,n);
        return (left&right);
          
           
  }
  
  bool maxHeap(struct Node* root){
     if(root->left==NULL && root->right==NULL)
     return true;
    
    if(root->right==NULL)
    return(root->data>root->left->data);
    
    bool left=maxHeap(root->left);
    bool right=maxHeap(root->right);
    
    if(left && right && root->data>root->left->data && root->data>root->right->data)
    return true;
    
    else
    return false;
  }
  
    bool isHeap(struct Node* root) {
        int n=countNodes(root);
        int index=0;
        if(isCBT(root,index,n) && maxHeap(root))
            return true;
        else
            return false;
    }
};
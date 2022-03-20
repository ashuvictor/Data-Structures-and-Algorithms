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
  int TreeSize(Node* root)
  {
      if(root==NULL)
      return NULL;
      return 1+TreeSize(root->left)+TreeSize(root->right);
  }
  int check(Node* root,int n,int index)
  {
      if(root==NULL)
      return 1;
      if(index>=n)
      return 0;
      if((root->left and root->left->data >=root->data) or (root->right and root->right->data>=root->data))
      return 0;
      return check(root->left,n,2*index+1) and check(root->right,n,2*index+2);
      
  }
    bool isHeap(struct Node* tree) {
        // code here
        if(tree==NULL)
        return true;
        int n=TreeSize(tree);
        int index=0;
        if(check(tree,n,index))
        return true;
        return false;
    }
};

bool isHeap(struct Node* root) {
        // code here
        if (!root || (!root->left && !root->right))
            return true;
        else if (root->right && !root->left)
            return false;
        else if (root->right && root->right->left && !root->left->right)
            return false;
        if (root->left->data > root->data)
            return false;
        if (root->right && root->right->data > root->data)
            return false;
        return isHeap(root->left) && isHeap(root->right);
    }